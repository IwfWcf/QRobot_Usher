#include "opencv2/core/core.hpp"
#include "opencv2/contrib/contrib.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
#include <fstream>
#include <sstream>

using namespace cv;
using namespace std;

const int g_howManyPhotoForTraining = 3;
//每个人取出8张作为训练
const int g_photoNumberOfOnePerson = 10;
//ORL数据库每个人10张图

vector<Mat> images, train_images, test_images;
vector<int> labels, train_labels, test_labels;
Ptr<FaceRecognizer> model;

static void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') 
{
    std::ifstream file(filename.c_str(), ifstream::in);
    if (!file) {
        string error_message = "No valid input file was given, please check the given filename.";
        CV_Error(CV_StsBadArg, error_message);
    }
    string line, path, classlabel;
    while (getline(file, line)) {
        stringstream liness(line);
        getline(liness, path, separator);
        getline(liness, classlabel);
        if(!path.empty() && !classlabel.empty()) {
            images.push_back(imread(path, 0));
            labels.push_back(atoi(classlabel.c_str()));
        }
    }
}

inline void train()
{
	string fn_csv = "database.csv";
	try {
        read_csv(fn_csv, images, labels);
    } catch (cv::Exception& e) {
        cerr << "Error opening file \"" << fn_csv << "\". Reason: " << e.msg << endl;
        // nothing more we can do
        exit(1);
    }
    // Quit if there are not enough images for this demo.
    if (images.size() <= 1) {
        string error_message = "This demo needs at least 2 images to work. Please add more images to your data set!";
        CV_Error(CV_StsError, error_message);
    }
	int photoNumber = images.size();
    for(int i=0 ; i<photoNumber ; i++) {
        if((i % g_photoNumberOfOnePerson) < g_howManyPhotoForTraining) {
            train_images.push_back(images[i]);
            train_labels.push_back(labels[i]);
        } else {
            test_images.push_back(images[i]);
            test_labels.push_back(labels[i]);
        }
    }
	model = createEigenFaceRecognizer();
    model->train(train_images, train_labels);
	model->save("lbph_at.yml");
}

inline void load()
{
	model = createLBPHFaceRecognizer();
	model->load("lbph_at.yml");
}

int main(int argc, const char *argv[]) 
{
	train();
	int iCorrectPrediction = 0, predictedLabel, testPhotoNumber = test_images.size();
    for(int i = 0; i < testPhotoNumber; i++) {
        predictedLabel = model->predict(test_images[i]);
        if(predictedLabel == test_labels[i])
            iCorrectPrediction++;
    }
    string result_message = format("Test Number = %d / Actual Number = %d.", testPhotoNumber, iCorrectPrediction);
    cout << result_message << endl;
    cout << "accuracy = " << float(iCorrectPrediction) / testPhotoNumber << endl;
	return 0;
}
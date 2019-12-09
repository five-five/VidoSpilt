#include <string>
#include <opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
	VideoCapture cap;
	if (!cap.open("rtsp://admin:admin123@10.50.90.2/Streaming/channels/201"))
	{
		std::cout << "Error opening video stream or file" << std::endl;
		return -1;
	}
	//Mat img;
	//for (int i = 0;; i++)
	//{
		//cap.read(img);
		//imshow("h", img);
		//waitKey(1);
	//}
	VideoWriter write;
	int w = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_WIDTH));
	int h = static_cast<int>(cap.get(CV_CAP_PROP_FRAME_HEIGHT));
	double r = cap.get(CV_CAP_PROP_FPS);
	Size S(w, h);
	string outFile = "E://test.avi";
	write.open(outFile, -1, r, S, true);
	if (!cap.isOpened())
	{
		return 1;
	}
	bool stop = false;
	Mat frame;
	while (!stop)
	{
		if (!cap.read(frame))
			break;
		imshow("Video", frame);
		write.write(frame);
		waitKey(1);
	}
	cap.release();
	write.release();
	cvDestroyWindow("Video");
	return 0;
}
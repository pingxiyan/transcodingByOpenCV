#include <iostream>
#include <opencv2/opencv.hpp>


int main(int argc, char** argv) {
	std::string srcfn = "C:\\Intel\\hddl\\hddl-samples-data\\test_video_crossroad\\cross_road_3_internaldoc_.avi";
	std::string dstfn = "dst.avi";
	if (argc == 2 && argv[1] == std::string("-h")) {
		std::cout << "argv[1] : src video file name" << std::endl;
		std::cout << "argv[2] : dst video file name" << std::endl;
		std::cout << "Note: need ffmpeg lig: " << std::endl;
		return 0;
	}
	else if(argc == 3) {
		srcfn = argv[1];
		dstfn = argv[2];
	}

	std::cout << "srcfn = " << srcfn << std::endl;
	std::cout << "dstfn = " << dstfn << std::endl;

	cv::VideoCapture _cap;
	_cap.open(srcfn);

	cv::VideoWriter vw;
	vw.open(dstfn, cv::VideoWriter::fourcc('h', '2', '6', '4'), 25 , cv::Size(1920, 1080));
	for (int i = 0;; i++) {
		cv::Mat frame;
		if (!_cap.read(frame)) {
			std::cout << "Failed to get frame from cv::VideoCapture" << std::endl;
			return 0;
		}
		std::cout << "\rframe : " << i;

		cv::Mat rsz;
		cv::resize(frame, rsz, cv::Size(1920, 1080));
		vw.write(rsz);

		if (i > 25) {
			break;
		}
	}
	std::cout << std::endl;

	return 0;
}
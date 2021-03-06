#ifndef _ANNOTATION_WINDOW_
#define _ANNOTATION_WINDOW_

#include <iostream>
#include <cmath>

//#include <commdlg.h>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/calib3d/calib3d.hpp>

//#include <mat.h>

#include "cvimage_view.hpp"
#include "feature_annotation_view.hpp"
#include "court_view.hpp"
#include "visualize_result.h"
#include "optimization/camera_estimation.hpp"
#include "io/io_util.hpp"



class AnnotationWindow {

private:
	// pointer for two views
	FeatureAnnotationView * feature_annotation_view_;
	CourtView * court_view_;
	VisualizeView * visualize_view_;

	// for hockey model
	std::vector<vgl_point_2d<double>> points_;

	// this is indexes for lines(two points) in hockey model
	std::vector<std::pair<int, int>> pairs_;

	// for camera refinement
	vpgl_perspective_camera<double> init_camera_; // camera from initial calibration
	vpgl_perspective_camera<double> opt_camera_; // refined camera

private:
	// frame for main control view
	Mat frame_;
	cv::String main_view_name_;

	AnnotationState state_;

	void mainControlHandler();
	void calibButtonFunc();
	void clearButtonFunc();
	void annotationStateFunc();

	void visualize_camera(vpgl_perspective_camera<double> camera);

	// Ice hockey specific
	bool refineCalibIceHockey();

	string img_index_;

public:
	// interface for annotation application
	AnnotationWindow(cv::String name, std::string index = "default");
	~AnnotationWindow();

	void setFeatureAnnotationView(FeatureAnnotationView* image_view);

	void setCourtView(CourtView* image_view);


	// main function to start window application
	void startLoop();
};

#endif

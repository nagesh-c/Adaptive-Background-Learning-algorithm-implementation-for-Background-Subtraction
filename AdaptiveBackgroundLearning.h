#pragma once

#include <iostream>
#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>

using namespace cv;
using namespace std;

class AdaptiveBackgroundLearning
{
private:
  bool firstTime;
  Mat img_background;
  double alpha;
  long limit;
  long counter;
  double minVal;
  double maxVal;
  bool enableThreshold;
  int threshold;
  bool showForeground;
  bool showBackground;

public:
  AdaptiveBackgroundLearning();
  ~AdaptiveBackgroundLearning();

  void process(const Mat &img_input, Mat &img_output, Mat &img_bgmodel);

private:
  void saveConfig();
  void loadConfig();
};

The Adapative Background Learning is a background subtraction algorithm which models the each frame, based on this model the background subtraction of the frames happen.

To execute :
	
	g++ -o output main.cpp AAdaptiveBackgroundLearning.cpp
	./output.out "videofile_path"
Or

in `main.cpp`, change VideoCapture call initialization to `0`, to apply for real camera.


Output will be:

	 Input Window
	 Background Subtracted Window
	 Modeling Window.

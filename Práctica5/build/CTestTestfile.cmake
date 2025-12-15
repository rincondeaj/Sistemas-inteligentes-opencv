# CMake generated Testfile for 
# Source directory: /home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/blur_background
# Build directory: /home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TestFSIVComputeDenseOpticalFlow "test_common_code" "fsiv_compute_dense_optical_flow")
set_tests_properties(TestFSIVComputeDenseOpticalFlow PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/blur_background/CMakeLists.txt;20;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/blur_background/CMakeLists.txt;0;")
add_test(TestFSIVComputeOpticalFlowMagnitude "test_common_code" "fsiv_compute_optical_flow_magnitude")
set_tests_properties(TestFSIVComputeOpticalFlowMagnitude PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/blur_background/CMakeLists.txt;21;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/blur_background/CMakeLists.txt;0;")
add_test(TestFSIVCreateStructuringElement "test_common_code" "fsiv_create_structuring_element")
set_tests_properties(TestFSIVCreateStructuringElement PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/blur_background/CMakeLists.txt;22;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/blur_background/CMakeLists.txt;0;")
add_test(TestFSIVComputeOfForegroundMask "test_common_code" "fsiv_compute_of_foreground_mask")
set_tests_properties(TestFSIVComputeOfForegroundMask PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/blur_background/CMakeLists.txt;23;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/blur_background/CMakeLists.txt;0;")
add_test(TestFSIVBlurBackground "test_common_code" "fsiv_blur_background")
set_tests_properties(TestFSIVBlurBackground PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/blur_background/CMakeLists.txt;24;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/blur_background/CMakeLists.txt;0;")

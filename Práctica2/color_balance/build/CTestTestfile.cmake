# CMake generated Testfile for 
# Source directory: /home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance
# Build directory: /home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TestFSIVColorRescaling "test_common_code" "fsiv_color_rescaling")
set_tests_properties(TestFSIVColorRescaling PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance/CMakeLists.txt;18;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance/CMakeLists.txt;0;")
add_test(TestFSIVConvertBgrToGray "test_common_code" "fsiv_convert_bgr_to_gray")
set_tests_properties(TestFSIVConvertBgrToGray PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance/CMakeLists.txt;19;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance/CMakeLists.txt;0;")
add_test(TestFSIVGrayWorldColorBalance "test_common_code" "fsiv_gray_world_color_balance")
set_tests_properties(TestFSIVGrayWorldColorBalance PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance/CMakeLists.txt;20;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance/CMakeLists.txt;0;")
add_test(TestFSIVComputeImageHistogram "test_common_code" "fsiv_compute_image_histogram")
set_tests_properties(TestFSIVComputeImageHistogram PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance/CMakeLists.txt;21;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance/CMakeLists.txt;0;")
add_test(TestFSIVComputeHistogramPercentile "test_common_code" "fsiv_compute_histogram_percentile")
set_tests_properties(TestFSIVComputeHistogramPercentile PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance/CMakeLists.txt;22;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance/CMakeLists.txt;0;")
add_test(TestFSIVWhitePatchColorBalance "test_common_code" "fsiv_white_patch_color_balance")
set_tests_properties(TestFSIVWhitePatchColorBalance PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance/CMakeLists.txt;23;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/color_balance/CMakeLists.txt;0;")

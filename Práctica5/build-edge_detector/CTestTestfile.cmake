# CMake generated Testfile for 
# Source directory: /home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector
# Build directory: /home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/build-edge_detector
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TestFSIVComputeDerivate "test_common_code" "fsiv_compute_derivate")
set_tests_properties(TestFSIVComputeDerivate PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;17;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")
add_test(TestFSIVComputeGradientMagnitude "test_common_code" "fsiv_compute_gradient_magnitude")
set_tests_properties(TestFSIVComputeGradientMagnitude PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;18;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")
add_test(TestFSIVComputeGradientHistogram "test_common_code" "fsiv_compute_gradient_histogram")
set_tests_properties(TestFSIVComputeGradientHistogram PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;19;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")
add_test(TestFSIVComputeHistogramPercentile "test_common_code" "fsiv_compute_histogram_percentile")
set_tests_properties(TestFSIVComputeHistogramPercentile PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;20;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")
add_test(TestFSIVHistogramIdxToValue "test_common_code" "fsiv_histogram_idx_to_value")
set_tests_properties(TestFSIVHistogramIdxToValue PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;21;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")
add_test(TestFSIVThiningEdgeMap "test_common_code" "fsiv_thinning_edge_map")
set_tests_properties(TestFSIVThiningEdgeMap PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;22;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")
add_test(TestFSIVPercentileEdgeDetector "test_common_code" "fsiv_percentile_edge_detector")
set_tests_properties(TestFSIVPercentileEdgeDetector PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;23;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")
add_test(TestFSIVOtsuEdgeDetector "test_common_code" "fsiv_otsu_edge_detector")
set_tests_properties(TestFSIVOtsuEdgeDetector PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;24;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")
add_test(TestFSIVCannyEdgeDetector "test_common_code" "fsiv_canny_edge_detector")
set_tests_properties(TestFSIVCannyEdgeDetector PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;25;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")
add_test(TestFSIVComputeGroundTruthImage "test_common_code" "fsiv_compute_ground_truth_image")
set_tests_properties(TestFSIVComputeGroundTruthImage PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;26;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")
add_test(TestFSIVComputeEdgeDetectorConfusionMatrix "test_common_code" "fsiv_compute_edge_detector_confusion_matrix")
set_tests_properties(TestFSIVComputeEdgeDetectorConfusionMatrix PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;27;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")
add_test(TestFSIVComputeSensitivity "test_common_code" "fsiv_compute_sensitivity")
set_tests_properties(TestFSIVComputeSensitivity PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;28;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")
add_test(TestFSIVComputePrecision "test_common_code" "fsiv_compute_precision")
set_tests_properties(TestFSIVComputePrecision PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;29;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")
add_test(TestFSIVComputeF1Score "test_common_code" "fsiv_compute_F1_score")
set_tests_properties(TestFSIVComputeF1Score PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;30;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica5/edge_detector/CMakeLists.txt;0;")

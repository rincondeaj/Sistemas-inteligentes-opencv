# CMake generated Testfile for 
# Source directory: /home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf
# Build directory: /home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/build-pollen_clf
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TestFSIVExtract01NormalizedGrayLevels "test_common_code" "fsiv_extract_01_normalized_graylevels")
set_tests_properties(TestFSIVExtract01NormalizedGrayLevels PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;49;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;0;")
add_test(TestFSIVCreateKNNClassifier "test_common_code" "fsiv_create_knn_classifier")
set_tests_properties(TestFSIVCreateKNNClassifier PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;50;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;0;")
add_test(TestFSIVCreateSVMClassifier "test_common_code" "fsiv_create_svm_classifier")
set_tests_properties(TestFSIVCreateSVMClassifier PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;51;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;0;")
add_test(TestFSIVCreateRTreesClassifier "test_common_code" "fsiv_create_rtrees_classifier")
set_tests_properties(TestFSIVCreateRTreesClassifier PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;52;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;0;")
add_test(TestFSIVTrainClassifier "test_common_code" "fsiv_train_classifier")
set_tests_properties(TestFSIVTrainClassifier PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;53;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;0;")
add_test(TestFSIVPredictLabels "test_common_code" "fsiv_predict_labels")
set_tests_properties(TestFSIVPredictLabels PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;54;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;0;")
add_test(TestFSIVLoadKNNClassifierModel "test_common_code" "fsiv_load_knn_classifier_model")
set_tests_properties(TestFSIVLoadKNNClassifierModel PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;55;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;0;")
add_test(TestFSIVLoadSVMClassifierModel "test_common_code" "fsiv_load_svm_classifier_model")
set_tests_properties(TestFSIVLoadSVMClassifierModel PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;56;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;0;")
add_test(TestFSIVLoadRTreesClassifierModel "test_common_code" "fsiv_load_rtrees_classifier_model")
set_tests_properties(TestFSIVLoadRTreesClassifierModel PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;57;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;0;")
add_test(TestFSIVComputeConfusionMatrix "test_common_code" "fsiv_compute_confusion_matrix")
set_tests_properties(TestFSIVComputeConfusionMatrix PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;58;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;0;")
add_test(TestFSIVComputeRecognitionRates "test_common_code" "fsiv_compute_recognition_rates")
set_tests_properties(TestFSIVComputeRecognitionRates PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;59;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;0;")
add_test(TestFSIVComputeAccuracy "test_common_code" "fsiv_compute_accuracy")
set_tests_properties(TestFSIVComputeAccuracy PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;60;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;0;")
add_test(TestFSIVComputeMeanRecognitionRate "test_common_code" "fsiv_compute_mean_recognition_rate")
set_tests_properties(TestFSIVComputeMeanRecognitionRate PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;61;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica6/pollen_clf/CMakeLists.txt;0;")

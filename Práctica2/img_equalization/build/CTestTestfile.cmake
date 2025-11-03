# CMake generated Testfile for 
# Source directory: /home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization
# Build directory: /home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TestFSIVComputeHistogram "test_common_code" "fsiv_compute_histogram")
set_tests_properties(TestFSIVComputeHistogram PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;20;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;0;")
add_test(TestFSIVNormalizeHistogram "test_common_code" "fsiv_normalize_histogram")
set_tests_properties(TestFSIVNormalizeHistogram PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;21;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;0;")
add_test(TestFSIVAccumulateHistogram "test_common_code" "fsiv_accumulate_histogram")
set_tests_properties(TestFSIVAccumulateHistogram PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;22;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;0;")
add_test(TestFSIVCreateEqualizationLookupTable "test_common_code" "fsiv_create_equalization_lookup_table")
set_tests_properties(TestFSIVCreateEqualizationLookupTable PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;23;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;0;")
add_test(TestFSIVComputeActualClippingHistogramValue "test_common_code" "fsiv_compute_actual_clipping_histogram_value")
set_tests_properties(TestFSIVComputeActualClippingHistogramValue PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;24;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;0;")
add_test(TestFSIVComputeClippedHistogram "test_common_code" "fsiv_compute_clipped_histogram")
set_tests_properties(TestFSIVComputeClippedHistogram PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;25;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;0;")
add_test(TestFSIVCreateEqualizationLookupTableWithCLAHE "test_common_code" "fsiv_create_equalization_lookup_table_with_clahe")
set_tests_properties(TestFSIVCreateEqualizationLookupTableWithCLAHE PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;26;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;0;")
add_test(TestFSIVApplyLookupTable "test_common_code" "fsiv_apply_lookup_table")
set_tests_properties(TestFSIVApplyLookupTable PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;27;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica2/img_equalization/CMakeLists.txt;0;")

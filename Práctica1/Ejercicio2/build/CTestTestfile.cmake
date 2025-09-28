# CMake generated Testfile for 
# Source directory: /home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica1/Ejercicio2/chroma_key
# Build directory: /home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica1/Ejercicio2/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(TestFSIVConvertBgrToHsv "test_common_code" "fsiv_convert_bgr_to_hsv")
set_tests_properties(TestFSIVConvertBgrToHsv PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica1/Ejercicio2/chroma_key/CMakeLists.txt;20;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica1/Ejercicio2/chroma_key/CMakeLists.txt;0;")
add_test(TestFSIVComputeChromaKeyMask "test_common_code" "fsiv_compute_chroma_key_mask")
set_tests_properties(TestFSIVComputeChromaKeyMask PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica1/Ejercicio2/chroma_key/CMakeLists.txt;21;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica1/Ejercicio2/chroma_key/CMakeLists.txt;0;")
add_test(TestFSIVCombineImages "test_common_code" "fsiv_combine_images")
set_tests_properties(TestFSIVCombineImages PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica1/Ejercicio2/chroma_key/CMakeLists.txt;22;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica1/Ejercicio2/chroma_key/CMakeLists.txt;0;")
add_test(TestFSIVApplyChromaKey "test_common_code" "fsiv_apply_chroma_key")
set_tests_properties(TestFSIVApplyChromaKey PROPERTIES  _BACKTRACE_TRIPLES "/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica1/Ejercicio2/chroma_key/CMakeLists.txt;23;add_test;/home/drizzt/Escritorio/Sistemas inteligentes en visión/Práctica1/Ejercicio2/chroma_key/CMakeLists.txt;0;")

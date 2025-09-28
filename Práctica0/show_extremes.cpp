#include <iostream>
#include <exception>

//OpenCV includes
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
//#include <opencv2/calib3d.hpp> //Uncomment when it was appropiated.
//#include <opencv2/ml.hpp> //Uncomment when it was appropiated.


#include "common_code.hpp"

const char * keys =
    "{help h usage ? |      | print this message}"
    "{w              |20    | Wait time (miliseconds) between frames.}"
    "{v              |      | the input is a video file.}"
    "{c              |      | the input is a camera index.}"    
    "{@input         |<none>| input <fname|int>}"
    ;




int
main (int argc, char* const* argv)
{
  int retCode=EXIT_SUCCESS;
  
  try {    

      cv::CommandLineParser parser(argc, argv, keys);
      parser.about("Show the extremes values and their locations.");
      if (parser.has("help"))
      {
          parser.printMessage();
          return 0;
      }
      bool is_video = parser.has("v");
      bool is_camera = parser.has("c");
      int wait = parser.get<int>("w");
      cv::String input = parser.get<cv::String>("@input");
      if (!parser.check())
      {
          parser.printErrors();
          return 0;
      }

    // TODO
        cv::Mat img = cv::imread(input, cv::IMREAD_ANYCOLOR);
        if (img.empty())
        {
          std::cerr << "Error: no he podido abrir el fichero '" << input << "'." << std::endl;
          return EXIT_FAILURE;
        }
        cv::namedWindow("IMG", cv::WINDOW_GUI_EXPANDED);
        cv::imshow("IMG", img);
        std::cout << "Pulsa ESC para salir." << std::endl;
        
        int channels = img.channels();
        std::vector<cv::uint8_t> min_v(channels);
        std::vector<cv::uint8_t> max_v(channels);
        std::vector<cv::Point> min_loc(channels);
        std::vector<cv::Point> max_loc(channels);

        fsiv_find_min_max_loc_1(img, min_v, max_v, min_loc, max_loc);
        
        // Imprimir resultados de los 4 vectores
        std::cout << "\n=== RESULTADOS DE MIN/MAX ===\n" << std::endl;
        
        for(int i = 0; i < channels; i++){
            std::cout << "Canal " << i << ":" << std::endl;
            std::cout << "  Valor mínimo: " << (int)min_v[i] 
                      << " en posición (" << min_loc[i].x << "," << min_loc[i].y << ")" << std::endl;
            std::cout << "  Valor máximo: " << (int)max_v[i] 
                      << " en posición (" << max_loc[i].x << "," << max_loc[i].y << ")" << std::endl;
            std::cout << std::endl;
        }
        
        std::cout << "Presiona ESC para salir..." << std::endl;
        
        while ((cv::waitKey(0) & 0xff) != 27); //Hasta que no se pulse la tecla ESC no salimos.

        //Debemos cerrar las ventanas abiertas.
        cv::destroyWindow("IMG");
    //    
  }
  catch (std::exception& e)
  {
    std::cerr << "Caught exception: " << e.what() << std::endl;
    retCode = EXIT_FAILURE;
  }
  catch (...)
  {
    std::cerr << "Caught unknown exception!" << std::endl;
    retCode = EXIT_FAILURE;
  }
  return retCode;
}

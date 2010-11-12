/*
 * image adjust.  Automatic image normalization.
 * Copyright (C) 2010 Joel Granados <joel.granados@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#include <opencv/cv.h>
#include <string.h>

/* command objective description */
enum ia_obj { NONE, CREATE_CONF, IMAGE_ADJUST, VIDEO_DEMO };

//Structure holding all the user input and some initial calculations.
struct ia_input
{
  string iif; //The intrinsic input file.

  cv::Mat camMat; //The camera matrix.
  cv::Mat disMat; //The distortion matrix.

  int camera_id;
  string vid_file; //Video file to use instead of the camera.
  vector<string> images; // a list of image file names.

  cv::Size b_size; //chessboard size. height x width

  float squareSize; //Chessboard square size

  int delay; //Delay between actions in the capture state.

  int num_in_img; // Number of images to calculate intrinsics.

  /* These will be the command objectives */
  ia_obj objective;

  /* Checks to see if the arguments have been checked */
  bool checked;
};

void ia_usage (const char*);
ia_input ia_init_input (int, char**);
void ia_print_input_struct (ia_input&);

void ia_create_config (const cv::Mat*, const cv::Mat*);

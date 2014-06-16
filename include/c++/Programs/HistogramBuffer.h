////////////////////////////////////////////////////////////////////////////////
//! @file	: HistogramBuffer.h
//! @date   : Jun 2014
//!
//! @brief  : Histogram calculation on images
//! 
//! Copyright (C) 2014 - CRVI
//!
//! This file is part of OpenCLIPP.
//! 
//! OpenCLIPP is free software: you can redistribute it and/or modify
//! it under the terms of the GNU Lesser General Public License version 3
//! as published by the Free Software Foundation.
//! 
//! OpenCLIPP is distributed in the hope that it will be useful,
//! but WITHOUT ANY WARRANTY; without even the implied warranty of
//! MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//! GNU Lesser General Public License for more details.
//! 
//! You should have received a copy of the GNU Lesser General Public License
//! along with OpenCLIPP.  If not, see <http://www.gnu.org/licenses/>.
//! 
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Program.h"

namespace OpenCLIPP
{

/// A program that calculates the Histogram of an image
class CL_API HistogramBuffer : public ImageBufferProgram
{
public:
   HistogramBuffer(COpenCL& CL)
   :  ImageBufferProgram(CL, "Histogram_Buffer.cl")
   { }

   /// Calculates the Histogram of the first channel of the image
   /// \param Histogram : Array of 256 elements that will receive the histogram values
   void Histogram1C(ImageBuffer& Source, uint * Histogram);

   /// Calculates the Histogram of all channels of the image
   /// \param Histogram : Array of 1024 elements that will receive the histogram values
   void Histogram4C(ImageBuffer& Source, uint * Histogram);

   /// Calculates the Otsu threshold given an histogram
   static uint OtsuThreshold(uint Histogram[256], uint NbPixels);

   /// Calculates the Otsu threshold for the image
   uint OtsuThreshold(ImageBuffer& Source);
};

}

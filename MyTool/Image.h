#pragma once

#ifndef IMAGE_H
#define IMAGE_H

namespace MyTool {

	using namespace System;
	using namespace System::IO;
	using namespace System::Drawing;

	array<System::Byte>^ imageToByteArray(Image^ imageIn);

	Image^ byteArrayToImage(array<System::Byte>^ byteArrayIn);

	array<System::Byte>^ GetImageForData(String^ path);

	String^ GetImageResolution(String^ path);

}

#endif

#include "Image.h"

namespace MyTool {

	using namespace System;
	using namespace System::IO;
	using namespace System::Drawing;


	array<System::Byte>^ imageToByteArray(Image^ imageIn)
	{
		MemoryStream^ ms = gcnew MemoryStream();
		imageIn->Save(ms, System::Drawing::Imaging::ImageFormat::Png);
		return ms->ToArray();
	}

	Image^ byteArrayToImage(array<System::Byte>^ byteArrayIn)
	{
		MemoryStream^ ms = gcnew MemoryStream(byteArrayIn);
		Image^ returnImage = Image::FromStream(ms);
		return returnImage;
	}

	array<System::Byte>^ GetImageForData(String^ path)
	{

		Bitmap^ image;
		Bitmap^ bmp;
		FileStream^ stream;
		//image = Bitmap();
		try
		{
			stream = gcnew FileStream(path, System::IO::FileMode::Open);
			bmp = gcnew Bitmap(stream);
			image = (Bitmap^)bmp->Clone();
			return imageToByteArray(image);
		}
		finally
		{
			delete stream;
			delete bmp;
		}

	}

	String^ GetImageResolution(String^ path)
	{

		Bitmap^ image;
		Bitmap^ bmp;
		FileStream^ stream;
		//image = Bitmap();
		try
		{
			stream = gcnew FileStream(path, System::IO::FileMode::Open);
			bmp = gcnew Bitmap(stream);
			image = (Bitmap^)bmp->Clone();
			return image->Width + "x" + image->Height;
		}
		finally
		{
			delete stream;
			delete bmp;
			delete image;
		}

	}

}
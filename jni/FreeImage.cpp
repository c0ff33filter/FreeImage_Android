#include <jni.h>
#include "org_example_freeimage_FreeImage.h"
#include "Source/FreeImage.h"


using namespace std;

/** Generic image loader
@param lpszPathName Pointer to the full file name
@param flag Optional load flag constant
@return Returns the loaded dib if successful, returns NULL otherwise
*/
extern "C" FIBITMAP* GenericLoader(const char* lpszPathName, int flag) {
  FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
  // check the file signature and deduce its format
  // (the second argument is currently not used by FreeImage)
  fif = FreeImage_GetFileType(lpszPathName, 0);
  if(fif == FIF_UNKNOWN) {
    // no signature ?
    // try to guess the file format from the file extension
    fif = FreeImage_GetFIFFromFilename(lpszPathName);
  }
  // check that the plugin has reading capabilities ...
  if((fif != FIF_UNKNOWN) && FreeImage_FIFSupportsReading(fif)) {
    // ok, let's load the file
    FIBITMAP *dib = FreeImage_Load(fif, lpszPathName, flag);
    // unless a bad file format, we are done !
    return dib;
}
  return NULL;
}

extern "C" JNIEXPORT jboolean JNICALL Java_org_example_freeimage_FreeImage_resize(
		JNIEnv * env, jobject jthis, jint width, jint height, jstring srcFile,
		jstring destFile) {
	FreeImage_Initialise();
	const char *srcFileString = env->GetStringUTFChars(srcFile, 0);
	const char *destFileString = env->GetStringUTFChars(destFile, 0);
	// load original bitmap from file
	FIBITMAP* srcBitmap = FreeImage_Load(FIF_JPEG, srcFileString, JPEG_DEFAULT);
	if (srcBitmap) { //load success
		//rescale bitmap
		FIBITMAP *rescaledBitmap = FreeImage_Rescale(srcBitmap, (int) width,
				(int) height, FILTER_BOX);
		FreeImage_Unload(srcBitmap);

		//save bitmap
		FreeImage_Save(FIF_JPEG, rescaledBitmap, destFileString,
				JPEG_QUALITYSUPERB);
		FreeImage_Unload(rescaledBitmap);

		env->ReleaseStringUTFChars(srcFile, srcFileString);
		env->ReleaseStringUTFChars(destFile, destFileString);
	} else {
		env->ReleaseStringUTFChars(srcFile, srcFileString);
		return JNI_FALSE;
	}

	FreeImage_DeInitialise();
	return JNI_TRUE;
}

extern "C" JNIEXPORT jboolean JNICALL Java_org_example_freeimage_FreeImag_crop(JNIEnv *env,
		jobject jthis, jint x1, jint y1, jint x2, jint y2, jstring srcFile,
		jstring destFile) {
	FreeImage_Initialise();

	const char *srcFileString = env->GetStringUTFChars(srcFile, 0);
	const char *destFileString = env->GetStringUTFChars(destFile, 0);
	// load original bitmap from file
	FIBITMAP* srcBitmap = FreeImage_Load(FIF_JPEG, srcFileString, JPEG_DEFAULT);

	if (srcBitmap) { //load success

		FIBITMAP *croppedBitmap = FreeImage_Copy(srcBitmap, x1, y1, x2, y2);
		FreeImage_Unload(srcBitmap);

		//save bitmap
		FreeImage_Save(FIF_JPEG, croppedBitmap, destFileString,
				JPEG_QUALITYSUPERB);
		FreeImage_Unload(croppedBitmap);

		env->ReleaseStringUTFChars(srcFile, srcFileString);
		env->ReleaseStringUTFChars(destFile, destFileString);

	} else {
		env->ReleaseStringUTFChars(srcFile, srcFileString);
		return JNI_FALSE;
	}

	FreeImage_DeInitialise();
	return JNI_TRUE;
}






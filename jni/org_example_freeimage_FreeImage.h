#include <jni.h>
#ifndef JNI_FALSE
#define JNI_FALSE 0
#endif
#ifndef JNI_TRUE
#define JNI_TRUE 1
#endif
#ifndef _Included_org_example_freeimage_FreeImage
#define _Included_org_example_freeimage_FreeImage
#ifdef __cplusplus
extern "C" {
#endif


JNIEXPORT jboolean JNICALL Java_org_example_freeimage_FreeImage_resize(
		JNIEnv * env, jobject jthis, jint width, jint height,
		jstring srcFile, jstring destFile);


JNIEXPORT jboolean JNICALL Java_org_example_freeimage_FreeImage_crop(JNIEnv *env, jobject jthis,jint x1,jint y1, jint x2, jint y2, jstring src, jstring dest);
#ifdef __cplusplus

}
#endif
#endif

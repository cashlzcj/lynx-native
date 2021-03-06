#ifndef BASE_ANDROID_LYNX_JAVA_TYPE_H_
#define BASE_ANDROID_LYNX_JAVA_TYPE_H_

#include "base/android/java_type.h"

namespace base {
namespace android {

const static char kLynxArrayType = 'b';
const static char kLynxObjectType = 'c';
const static char kLynxFunctionObjectType = 'd';
const static char kLynxHolderType = 'e';


class LxJType : public JType {
 public:
  // LynxArray
  static ScopedLocalJavaRef<jobject> NewLynxArray(JNIEnv* env, int length);
  static void SetLynxArrayElement(JNIEnv* env,
                                  jobject array,
                                  int index,
                                  jobject obj);
  static ScopedLocalJavaRef<jobject> GetLynxArrayElement(JNIEnv* env,
                                                         jobject array,
                                                         int index);
  static jstring GetLynxArrayElementTypes(JNIEnv* env, jobject array);
  static jint GetLynxArrayLength(JNIEnv* env, jobject array);

  // LynxObject
  static ScopedLocalJavaRef<jobject> NewLynxObject(JNIEnv* env);
  static void SetLynxObjectProperties(JNIEnv* env,
                                      jobject jjsobj,
                                      jobject array);
  static void SetLynxObjectProperty(JNIEnv* env,
                                    jobject jjsobj,
                                    jobject key,
                                    jobject value);
  static ScopedLocalJavaRef<jobject> GetLynxObjectProperties(JNIEnv* env,
                                                             jobject jjsobj);

  // LynxObject
  static long GetNativeLynxHolder(JNIEnv* env, jobject holder);

  static void Init(JNIEnv* env, char type);

 private:
  static void EnsureInstance(JNIEnv* env, char type);
  // LynxArray
  static jclass lynx_array_clazz;
  static jmethodID lynx_array_ctor;
  static jmethodID lynx_array_set_method;
  static jmethodID lynx_array_get_method;
  static jmethodID lynx_array_get_element_type_method;
  static jmethodID lynx_array_length_method;

  // LynxObject
  static jclass lynx_object_clazz;
  static jmethodID lynx_object_ctor;
  static jmethodID lynx_object_set_properties_method;
  static jmethodID lynx_object_set_property_method;
  static jmethodID lynx_object_get_properties_method;

  // LynxHolder
  static jclass lynx_holder_clazz;
  static jmethodID lynx_holder_get_native_holder_method;
};

}  // namespace android
}  // namespace base

#endif  // BASE_ANDROID_LYNX_JAVA_TYPE_H_
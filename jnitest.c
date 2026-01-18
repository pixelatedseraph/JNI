#include <jni.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
    JavaVM *jvm;
    JNIEnv *env;

    JavaVMInitArgs vm_args;
    JavaVMOption options[1];
    
    options[0].optionString = "-Djava.class.path=. --enable-native-access=ALL-UNNAMED";

    vm_args.version = JNI_VERSION_1_8;
    vm_args.nOptions = 1;
    vm_args.options = options;
    vm_args.ignoreUnrecognized = JNI_FALSE;

    // start JVM
    JNI_CreateJavaVM(&jvm, (void**)&env, &vm_args);

    // load class
    jclass cls = (*env)->FindClass(env, "LinkedListJNI");

    // constructor
    jmethodID ctor = (*env)->GetMethodID(env, cls, "<init>", "()V");
    jobject obj = (*env)->NewObject(env, cls, ctor);

    // method IDs
    jmethodID insert = (*env)->GetMethodID(env, cls, "Jinsert", "(Ljava/lang/Object;)V");
    jmethodID print  = (*env)->GetMethodID(env, cls, "Jprint", "()V");

    // java strings
    jstring s1 = (*env)->NewStringUTF(env, "mazeed");
    jstring s2 = (*env)->NewStringUTF(env, "faizan");
    jstring s3 = (*env)->NewStringUTF(env, "kowshik");

    // call Java methods
    (*env)->CallVoidMethod(env, obj, insert, s1);
    (*env)->CallVoidMethod(env, obj, insert, s2);
    (*env)->CallVoidMethod(env, obj, insert, s3);

    (*env)->CallVoidMethod(env, obj, print);

    // shutdown JVM
    (*jvm)->DestroyJavaVM(jvm);
}

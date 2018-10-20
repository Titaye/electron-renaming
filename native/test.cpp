#include <node.h>
#include <nan.h>

using v8::FunctionTemplate;
using v8::Handle;
using v8::Object;
using v8::Boolean;
using v8::String;
using v8::Number;
using v8::Exception;
using v8::Function;
using v8::Local;
using v8::Value;
using v8::ArrayBuffer;
using v8::ArrayBufferCreationMode;
using v8::Isolate;
using Nan::HandleScope;
using Nan::GetFunction;
using Nan::New;
using Nan::Set;
using Nan::Callback;
using Nan::To;
using Nan::ThrowError;
using Nan::CopyBuffer;


NAN_METHOD(Start) {
	info.GetReturnValue().Set(Nan::New<String>("from native").ToLocalChecked());
}


NAN_MODULE_INIT(InitAll) {
	Set(target, New<String>("start").ToLocalChecked(),
		GetFunction(New<FunctionTemplate>(Start)).ToLocalChecked());
}

NODE_MODULE(addon, InitAll)

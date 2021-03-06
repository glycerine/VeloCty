#include"helper.hpp"
#include "complexdatahandler.h"
int getNumElem(dim_type * dims, dim_type ndims){
        int numel=1;

        for(int i=0;i<ndims;i++ ){
                numel*=dims[i];
        }
        return numel;
}

bool checkNdims(int ndims_a, int ndims_b) {
  return ndims_a==ndims_b;
}

bool checkdim(int dim_a, int dim_b) {
  return dim_a==dim_b;
}

VrArrayPtrI64 getVrArrayI64(mxArray* arr){
	VrArrayPtrI64 out(static_cast<long*>(mxGetData(arr)),(dim_type*)mxGetDimensions(arr),mxGetNumberOfDimensions(arr));
	return out;
}
VrArrayPtrF64 getVrArrayF64(mxArray* arr){
	VrArrayPtrF64 out(mxGetPr(arr),(dim_type*)mxGetDimensions(arr),mxGetNumberOfDimensions(arr));
	return out;
}
VrArrayPtrF32 getVrArrayF32(mxArray* arr){
	VrArrayPtrF32 out;
	VR_GET_DATA_F32(out)=(float*)mxGetData(arr);
	VR_GET_NDIMS_F32(out)=mxGetNumberOfDimensions(arr);
	VR_GET_DIMS_F32(out)=(dim_type*)mxGetDimensions(arr);
	return out;
}

VrArrayPtrB getVrArrayB(mxArray* arr){
	VrArrayPtrB out;//=(VrArrayPtrB)VR_MALLOC(sizeof(VrArrayB));
	VR_GET_DATA_B(out)=(bool*)mxGetData(arr);
	VR_GET_NDIMS_B(out)=mxGetNumberOfDimensions(arr);
	VR_GET_DIMS_B(out)=(dim_type*)mxGetDimensions(arr);
	return out;
}

VrArrayPtrCF64 getVrArrayCF64(mxArray * arr){

        VrArrayPtrCF64 out;//=(VrArrayPtrCF64)VR_MALLOC(sizeof(VrArrayCF64));
	VR_GET_DATA_CF64(out)=mat_getComplexDataCF64(arr);
	VR_GET_NDIMS_CF64(out)=mxGetNumberOfDimensions(arr);
	VR_GET_DIMS_CF64(out)=(dim_type*)mxGetDimensions(arr);
	return out;
}

VrArrayPtrCF32 getVrArrayCF32(mxArray* arr){
    VrArrayPtrCF32 out;//=(VrArrayPtrCF32)VR_MALLOC(sizeof(VrArrayCF32));
	VR_GET_DATA_CF32(out)=mat_getComplexDataCF32(arr);
	VR_GET_NDIMS_CF32(out)=mxGetNumberOfDimensions(arr);
	VR_GET_DIMS_CF32(out)=(dim_type*)mxGetDimensions(arr);
	return out;
}


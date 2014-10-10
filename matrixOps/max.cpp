#include<library_ops.hpp>
#include<max.tpp>

double max_scalar(VrArrayPtrF64 A) {
    return max<VrArrayPtrF64,double>(A);     
}

float max_scalar(VrArrayPtrF32 A) {
    return max<VrArrayPtrF32,float>(A);     
}

VrArrayPtrF64 max(VrArrayPtrF64 A) {
	dim_type collapseDim = getIndexOfFirstNonSingletonDim<VrArrayPtrF64,dim_type>(A);
	dim_type step = getStep<VrArrayPtrF64,dim_type>(A,collapseDim);
	dim_type size = getSize<VrArrayPtrF64,dim_type>(A,collapseDim);	
	dim_type *dims = static_cast<dim_type*>(VR_MALLOC(sizeof(dim_type)*A.ndims));
	memcpy(dims,A.dims,sizeof(dim_type)*A.ndims);
	dims[collapseDim] = 1;
    dim_type bucketSize = getCollapsedDimension<VrArrayPtrF64,dim_type>(A,collapseDim);
	int ndims = A.ndims;
	VrArrayPtrF64 outArr = vrAllocArrayF64RM(ndims,0,dims);
	VR_GET_DATA_F64(outArr) = max<double,dim_type>(VR_GET_DATA_F64(A),collapseDim,bucketSize,size,step);
	return outArr;
} 
VrArrayPtrF32 max(VrArrayPtrF32 A) {
	dim_type collapseDim = getIndexOfFirstNonSingletonDim<VrArrayPtrF32,dim_type>(A);
	dim_type step = getStep<VrArrayPtrF32,dim_type>(A,collapseDim);
	dim_type size = getSize<VrArrayPtrF32,dim_type>(A,collapseDim);	
	dim_type *dims = static_cast<dim_type*>(VR_MALLOC(sizeof(dim_type)*A.ndims));
	memcpy(dims,A.dims,sizeof(dim_type)*A.ndims);
	dims[collapseDim] = 1;
    dim_type bucketSize = getCollapsedDimension<VrArrayPtrF32,dim_type>(A,collapseDim);
	int ndims = A.ndims;
	VrArrayPtrF32 outArr = vrAllocArrayF32RM(ndims,0,dims);
	VR_GET_DATA_F32(outArr) = max<float,dim_type>(VR_GET_DATA_F32(A),collapseDim,bucketSize,size,step);
	return outArr;
} 
VrArrayPtrCF32 max(VrArrayPtrCF32 A) {
	dim_type collapseDim = getIndexOfFirstNonSingletonDim<VrArrayPtrCF32,dim_type>(A);
	dim_type step = getStep<VrArrayPtrCF32,dim_type>(A,collapseDim);
	dim_type size = getSize<VrArrayPtrCF32,dim_type>(A,collapseDim);	
	dim_type *dims = static_cast<dim_type*>(VR_MALLOC(sizeof(dim_type)*A.ndims));
	memcpy(dims,A.dims,sizeof(dim_type)*A.ndims);
	dims[collapseDim] = 1;
    dim_type bucketSize = getCollapsedDimension<VrArrayPtrCF32,dim_type>(A,collapseDim);
	int ndims = A.ndims;
	VrArrayPtrCF32 outArr = vrAllocArrayF32CM(ndims,0,dims);
	VR_GET_DATA_CF32(outArr) = max<dim_type>(VR_GET_DATA_CF32(A),collapseDim,bucketSize,size,step);
	return outArr;
} 
VrArrayPtrCF64 max(VrArrayPtrCF64 A) {
	dim_type collapseDim = getIndexOfFirstNonSingletonDim<VrArrayPtrCF64,dim_type>(A);
	dim_type step = getStep<VrArrayPtrCF64,dim_type>(A,collapseDim);
	dim_type size = getSize<VrArrayPtrCF64,dim_type>(A,collapseDim);	
	dim_type *dims = static_cast<dim_type*>(VR_MALLOC(sizeof(dim_type)*A.ndims));
	memcpy(dims,A.dims,sizeof(dim_type)*A.ndims);
	dims[collapseDim] = 1;
    dim_type bucketSize = getCollapsedDimension<VrArrayPtrCF64,dim_type>(A,collapseDim);
	int ndims = A.ndims;
	VrArrayPtrCF64 outArr = vrAllocArrayF64CM(ndims,0,dims);
	VR_GET_DATA_CF64(outArr) = max<dim_type>(VR_GET_DATA_CF64(A),collapseDim,bucketSize,size,step);
	return outArr;
}

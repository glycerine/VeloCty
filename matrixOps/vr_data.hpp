#ifndef __VR_DATA_H__
#define __VR_DATA_H__
#include "string.h"
#include<complex.h>
#include<cstdlib>
#include<stdio.h>
#include "mex.h"
#define VR_MALLOC(x) mxMalloc(x)
typedef int dim_type;
typedef enum Layout{
  COLUMN_MAJOR,ROW_MAJOR
}Layout;

struct VrIndex;
struct VrArrayI64;
typedef struct VrArrayF64{
  double *data;
  dim_type* dims;  
  int ndims;
  Layout layout;
  VrArrayF64(){
    data=NULL;
    dims=NULL;
    ndims=0;
  }

  VrArrayF64(VrArrayF64 *);

  VrArrayF64(double* data, int *dims, int ndims ):data(data),dims(dims),ndims(ndims) {
  }
  VrArrayF64(VrArrayI64);
  VrArrayF64(double scal) :ndims(2) {
      data = static_cast<double*>(VR_MALLOC(sizeof(double)));
      *data = scal;
      dims  = static_cast<dim_type*>(VR_MALLOC(sizeof(dim_type)*2));
      dims[0] = 1;
      dims[1] = 1;
  }

  VrArrayF64(dim_type ndims,dim_type *dims);
  dim_type numelSliced(VrIndex*,dim_type);
  dim_type* dimsSliced(VrIndex*, dim_type);
  VrArrayF64 sliceArray(int nargs, ...);
  void sliceArray(VrArrayF64 *A, int nargs, ...);
  void  sliceArraySpec(VrArrayF64 *outArr, VrIndex row ,VrIndex col);
  void  sliceArraySpec(VrArrayF64 *outArr, VrIndex row ,VrIndex col,VrIndex index_3);
  void  sliceArraySpec(VrArrayF64 *outArr, VrIndex row);
  void setArraySliceSpec(VrArrayF64 inArr,VrIndex row, VrIndex col);
  void setArraySliceSpec(VrArrayF64 inArr,VrIndex row);
  void setArraySliceSpec(VrArrayF64 inArr,VrIndex row, VrIndex col,VrIndex index_3);
  void setArraySlice(VrArrayF64 inArr,int nargs, ...);
  VrArrayF64 sliceArraySpec(VrIndex row,VrIndex col );
  VrArrayF64 sliceArraySpec(VrIndex row);
  VrArrayF64 sliceArraySpec(VrIndex row,VrIndex col,VrIndex index_3);
}VrArrayF64;

typedef struct VrArrayF32{
  float *data;
  dim_type* dims;  
  int ndims;
  VrArrayF32(){
    data=NULL;
    dims=NULL;
    ndims=0;
  }
  VrArrayF32(float* data, int *dim_type, int ndims ):data(data),dims(dims),ndims(ndims){
  }
  dim_type numelSliced(VrIndex*,dim_type);
  dim_type* dimsSliced(VrIndex*, dim_type);
  VrArrayF32 operator()(int nargs, ...);
}VrArrayF32;

typedef struct VrArrayI64{
  long *data;
  dim_type* dims;  
  int ndims;
  dim_type numelSliced(VrIndex*,dim_type);
  dim_type* dimsSliced(VrIndex*, dim_type);
  VrArrayI64(long* data, int *dims, int ndims ):data(data),dims(dims),ndims(ndims) {
  }
  VrArrayI64():data(NULL),dims(NULL),ndims(0) {
  }
  VrArrayI64(dim_type ndims,dim_type *dims);
}VrArrayI64;

typedef struct VrArrayI32{
  int *data;
  dim_type* dims;  
  int ndims;
  dim_type numelSliced(VrIndex*,dim_type);
  dim_type* dimsSliced(VrIndex*, dim_type);
  VrArrayI32 operator()(int nargs, ...);
}VrArrayI32;

typedef struct VrArrayCF64{
  double complex  *data;
  dim_type* dims;  
  int ndims;
  dim_type numelSliced(VrIndex*,dim_type);
  dim_type* dimsSliced(VrIndex*, dim_type);
  VrArrayCF64 operator()(int nargs, ...);
}VrArrayCF64;

typedef struct VrArrayCF32{
  float complex *data;
  dim_type* dims;  
  int ndims;
  dim_type numelSliced(VrIndex*,dim_type);
  dim_type* dimsSliced(VrIndex*, dim_type);
  VrArrayCF32 operator()(int nargs, ...);
}VrArrayCF32;


typedef struct VrArrayB{
  bool *data;
  dim_type* dims;  
  int ndims;
    VrArrayB() {
        data = NULL;
        dims = NULL;
        ndims = 0;
    }
}VrArrayB;

struct VrIndex{
	bool m_isRange;
	bool m_isArray;
  	VrArrayF64 arr;		
	union Val{
		dim_type const_val;
		dim_type range_val[3];
	}m_val;
	VrIndex(dim_type const_val):m_isRange(false),m_isArray(false){
		m_val.const_val = const_val;
	}
	VrIndex(dim_type start,dim_type stop,dim_type step){
		m_isRange = true;
		m_isArray = false;
		m_val.range_val[0] = start;
		m_val.range_val[1] = stop;
		m_val.range_val[2] = step;	
	}
	
	VrIndex(VrArrayF64 A) {	
// 		dim_type  numel = 1;
// 		for(int i = 0; i < A.ndims; i++) {
// 			numel *= A.dims[i];
// 		}
// 		dim_type diff = static_cast<dim_type>(A.data[1] - A.data[0]);
// 		dim_type start = static_cast<dim_type>(A.data[0]);
// 		m_isRange = true;
// 		for(int i =1; i < numel-1; i++) {
// 			if(static_cast<dim_type>(A.data[i + 1] - A.data[i]) != diff) {
// 				m_isRange = false;
// 				m_isArray = true;
// 				break;
// 			}
// 		}
// 		if(m_isRange) {
// 			m_val.range_val[0] = start;
// 			m_val.range_val[1] = static_cast<dim_type>(A.data[numel - 1]);
// 			m_val.range_val[2] = diff;
// 		} else {
			arr = A;
			m_isArray = true;
			m_isRange = false;
	//	}
	}
	VrIndex() {
	}	
};
#endif

typedef int32_t INT32;
typedef unsigned char	UINT8;
typedef signed char		S8;
typedef unsigned short	UINT16;
typedef signed	 short	S16;
typedef unsigned long	UINT32;
//函数功能：
//	返回算法版本号
//输入：
//	pVersion：100字节大小的数据指针
//输出：
//	无
void SY_GetSYAlgVersion(UINT8* pVersion);

//函数功能：
//	返回特征长度（字节为单位）
//输入：
//	无
//输出：
//	特征长度（字节为单位）
INT32 SY_GetFeatureSize(void);

//函数功能：
//	返回模板长度（字节为单位）
//输入：
//	无
//输出：
//	模板长度（字节为单位）
INT32 SY_GetTempletSize(void);

//函数功能：
//	提取指纹特征
//输入：
//	pImage：输入图像地址
//	w：图像宽度
//	h：图像高度
//	pFeature：提取出的特征地址（特征长度由SY_GetFeatureSize函数得到）
//输出：
//	0：成功
//	其他：失败
//注：
//	提取特征后图像数据可能发生变化
INT32 SY_GetA3Feature(UINT8* pImage,INT32 w,INT32 h,UINT8 *pFeature);

//函数功能：
//	将特征加入到模板中
//输入：
//	pTemplet：输入模板地址（模板长度由SY_GetTempletSize函数得到）
//	pFeature：输入特征地址（特征长度由SY_GetFeatureSize函数得到）
//	IfEnroll：是否在录入，录入时输入1，其他情况输入0
//输出：
//	0：成功
//	其他：失败
INT32 SY_AddFeatureToTemplet(UINT8 *pTemplet,UINT8 *pFeature,UINT8 IfEnroll);

//函数功能：
//	特征和模板比对
//输入：
//	pTemplet：输入模板地址（模板长度由SY_GetTempletSize函数得到）
//	pFeature：输入特征地址（特征长度由SY_GetFeatureSize函数得到）
//输出：
//	比对分数
INT32 SY_TempletFeatureMatch(UINT8 *pTemplet,UINT8 *pFeature);

//函数功能：
//	得到模板质量
//输入：
//	pTemplet：输入模板地址（模板长度由SY_GetTempletSize函数得到）
//输出：
//	质量分数（0~100）
INT32 SY_GetTempletQuality(UINT8* pTemplet);

//函数功能：
//	得到图像质量
//输入：
//	pImage：输入图像地址
//	w：图像宽度
//	h：图像高度
//输出：
//	质量分数（0~100）
INT32 SY_GetImageQuality(UINT8* pImage,INT32 ImageX,INT32 ImageY);

//函数功能：
//	读取特定ID号模板的一定字节的内容
//输入：
//	ID号：（0开始）
//	读取的数据存放地址
//	读取数据相对这个模板的偏移
//  读取数据个数
//输出：
//	0：读取成功
//	其他：读取失败或其他错误
typedef INT32(*F_ReadModel)(UINT32,UINT8*,UINT32,UINT32);

//函数功能：
//	已知特征，在模板库中搜索对应ID
//输入：
//	Feature：输入特征地址
//	ReadMFunction：读取模板的回调函数
//	StartID：开始搜索ID号
//  SearchIDNumber：总共搜索的ID个数
//	SearchIndex：模板索引表（0：表示对应ID无模板，其他表示对应ID有模板）
//	pFindID：最后找到的ID号
//	pScore：找到ID号对应的比对得分
//	pNewTemplet：更新后的模板（pNewTemplet[0]=0表示没有更新，其他表示有更新）
//输出：
//	0：搜索成功，找到对应ID号
//	其他：搜索失败，或者其他错误
INT32 SY_SearchIDInTemplet(UINT8* Feature,F_ReadModel ReadMFunction,UINT32 StartID,UINT32 SearchIDNumber,UINT8* SearchIndex,INT32* pFindID,INT32* pScore,UINT8* pNewTemplet);

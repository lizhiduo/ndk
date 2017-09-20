typedef int32_t INT32;
typedef unsigned char	UINT8;
typedef signed char		S8;
typedef unsigned short	UINT16;
typedef signed	 short	S16;
typedef unsigned long	UINT32;
//�������ܣ�
//	�����㷨�汾��
//���룺
//	pVersion��100�ֽڴ�С������ָ��
//�����
//	��
void SY_GetSYAlgVersion(UINT8* pVersion);

//�������ܣ�
//	�����������ȣ��ֽ�Ϊ��λ��
//���룺
//	��
//�����
//	�������ȣ��ֽ�Ϊ��λ��
INT32 SY_GetFeatureSize(void);

//�������ܣ�
//	����ģ�峤�ȣ��ֽ�Ϊ��λ��
//���룺
//	��
//�����
//	ģ�峤�ȣ��ֽ�Ϊ��λ��
INT32 SY_GetTempletSize(void);

//�������ܣ�
//	��ȡָ������
//���룺
//	pImage������ͼ���ַ
//	w��ͼ����
//	h��ͼ��߶�
//	pFeature����ȡ����������ַ������������SY_GetFeatureSize�����õ���
//�����
//	0���ɹ�
//	������ʧ��
//ע��
//	��ȡ������ͼ�����ݿ��ܷ����仯
INT32 SY_GetA3Feature(UINT8* pImage,INT32 w,INT32 h,UINT8 *pFeature);

//�������ܣ�
//	���������뵽ģ����
//���룺
//	pTemplet������ģ���ַ��ģ�峤����SY_GetTempletSize�����õ���
//	pFeature������������ַ������������SY_GetFeatureSize�����õ���
//	IfEnroll���Ƿ���¼�룬¼��ʱ����1�������������0
//�����
//	0���ɹ�
//	������ʧ��
INT32 SY_AddFeatureToTemplet(UINT8 *pTemplet,UINT8 *pFeature,UINT8 IfEnroll);

//�������ܣ�
//	������ģ��ȶ�
//���룺
//	pTemplet������ģ���ַ��ģ�峤����SY_GetTempletSize�����õ���
//	pFeature������������ַ������������SY_GetFeatureSize�����õ���
//�����
//	�ȶԷ���
INT32 SY_TempletFeatureMatch(UINT8 *pTemplet,UINT8 *pFeature);

//�������ܣ�
//	�õ�ģ������
//���룺
//	pTemplet������ģ���ַ��ģ�峤����SY_GetTempletSize�����õ���
//�����
//	����������0~100��
INT32 SY_GetTempletQuality(UINT8* pTemplet);

//�������ܣ�
//	�õ�ͼ������
//���룺
//	pImage������ͼ���ַ
//	w��ͼ����
//	h��ͼ��߶�
//�����
//	����������0~100��
INT32 SY_GetImageQuality(UINT8* pImage,INT32 ImageX,INT32 ImageY);

//�������ܣ�
//	��ȡ�ض�ID��ģ���һ���ֽڵ�����
//���룺
//	ID�ţ���0��ʼ��
//	��ȡ�����ݴ�ŵ�ַ
//	��ȡ����������ģ���ƫ��
//  ��ȡ���ݸ���
//�����
//	0����ȡ�ɹ�
//	��������ȡʧ�ܻ���������
typedef INT32(*F_ReadModel)(UINT32,UINT8*,UINT32,UINT32);

//�������ܣ�
//	��֪��������ģ�����������ӦID
//���룺
//	Feature������������ַ
//	ReadMFunction����ȡģ��Ļص�����
//	StartID����ʼ����ID��
//  SearchIDNumber���ܹ�������ID����
//	SearchIndex��ģ��������0����ʾ��ӦID��ģ�壬������ʾ��ӦID��ģ�壩
//	pFindID������ҵ���ID��
//	pScore���ҵ�ID�Ŷ�Ӧ�ıȶԵ÷�
//	pNewTemplet�����º��ģ�壨pNewTemplet[0]=0��ʾû�и��£�������ʾ�и��£�
//�����
//	0�������ɹ����ҵ���ӦID��
//	����������ʧ�ܣ�������������
INT32 SY_SearchIDInTemplet(UINT8* Feature,F_ReadModel ReadMFunction,UINT32 StartID,UINT32 SearchIDNumber,UINT8* SearchIndex,INT32* pFindID,INT32* pScore,UINT8* pNewTemplet);

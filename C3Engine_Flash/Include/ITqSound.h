/********************************************************************
Created:		2006_4_25 9:18
Filename:		ITqSound.h
Author:		    lhq
Purpose:		
********************************************************************/
#ifndef _ITQSOUND_H_2006_4_25_9_18
#define _ITQSOUND_H_2006_4_25_9_18
//////////////////////////////////////////////////////////////////////
/*#ifdef TQSOUND_EXPORTS
#define TQSOUND_API __declspec(dllexport)
#else
#define TQSOUND_API __declspec(dllimport)
#endif*/
//#define TQSOUND_EXPORTS	//�ȱ���ͨ������

#define TQSOUND_EXPORTS

//////////////////////////////////////////////////////////////////////
enum TQSRESULT
{
	TQR_OK					=		0, // ����
	TQR_PARAMETER_ERROR		=		1, // ����������
	TQR_FILENAME_ERROR		=		2, // ��ʶ����ļ���
	TQR_AL_ERROR			=		3, // AL����
	TQR_FILE_OPEN_ERROR		=		4, // ���ļ�ʧ��
	TQR_FILETYPE_ERROR		=		5, // �ļ����ʹ���(��ʶ����ļ�����) 
	TQR_NOINIT				=		6,	// δ��ʼ��
};
//////////////////////////////////////////////////////////////////////
enum ENVIRONMENT
{
    ENVIRONMENT_GENERIC,			//��ͨ		
	ENVIRONMENT_PADDEDCELL,			//��淿
	ENVIRONMENT_ROOM,				//�շ���
	ENVIRONMENT_BATHROOM,			//ԡ��
	ENVIRONMENT_LIVINGROOM,			//����
	ENVIRONMENT_STONEROOM,			//ʯ�ʷ���
	ENVIRONMENT_AUDITORIUM,			//����
	ENVIRONMENT_CONCERTHALL,		//������
	ENVIRONMENT_CAVE,				//��Ѩ
	ENVIRONMENT_ARENA,				//Բ�ξ糡������̨
	ENVIRONMENT_HANGAR,				//�ɻ���
	ENVIRONMENT_CARPETEDHALLWAY,	//����̺����
	ENVIRONMENT_HALLWAY,			//����
	ENVIRONMENT_STONECORRIDOR,		//ʯ��ͨ��
	ENVIRONMENT_ALLEY,				//С��
	ENVIRONMENT_FOREST,				//ɭ��
	ENVIRONMENT_CITY,				//����
	ENVIRONMENT_MOUNTAINS,			//Ⱥɽ
	ENVIRONMENT_QUARRY,				//��ʯ��
	ENVIRONMENT_PLAIN,				//�տ���
	ENVIRONMENT_PARKINGLOT,			//ͣ����
	ENVIRONMENT_SEWERPIPE,			//��ˮ�ܵ�
	ENVIRONMENT_UNDERWATER,			//ˮ��
	ENVIRONMENT_DRUGGED,			//����
	ENVIRONMENT_DIZZY,				//ѣ��
	ENVIRONMENT_PSYCHOTIC,			//������
	ENVIRONMENT_COUNT
};
enum PlayStatus
{
	StatusInit = 0,
	StatusPlaying,
	StatusStop,
	StatusPause,
};

//////////////////////////////////////////////////////////////////////

void setEnvPath(const char* lpszPath);

//////////////////////////////////////////////////////////////////////
class ISound
{
public:
	// ���ͷŽӿ�
	virtual		TQSRESULT	Release(void)									=	0;

	//���������ļ�������3DЧ��
	virtual		TQSRESULT	PlaySound(const char* lpszFileName, long nLoop=0, long nVolume=100)	=	0;

	//���������ļ�����3DЧ��
	virtual		TQSRESULT	Play3DSound( const char* lpszFileName, float fWorldX, float fWorldY, float fWorldZ,
										float fMaxDistance=50, long nLoop=0, long nVolume=100, bool bPlay=true ) =	0;

	//���ڴ��в���������lpszFileName����������
	virtual		TQSRESULT PlaySoundByBuffer( const char* lpszFileName, const char* pBuffer, long lSize, long nLoop=0, long nVolume=100)	=	0;
	virtual		TQSRESULT Play3DSoundByBuffer( const char* lpszFileName, const char* pBuffer, long lSize, float fWorldX, float fWorldY, float fWorldZ,
										float fMaxDistance, long nLoop=0, long nVolume=100, bool bPlay=true )	=	0;

	//ֹͣ���������ļ�
	virtual		void	Stop(void)												=	0;

	//��ͣ���������ļ�
	virtual		void	Pause(void)												=	0;
	
	//�Ƿ��ڲ���
	virtual		PlayStatus	GetState(void)										=	0;

	//���²���ĳ�������ļ�
	virtual		bool	RePlay(void)											=	0;
	
	//�������������ļ�
	virtual		bool	Continue(void)											=	0;

	//��������(0~100)
	virtual		bool	SetVolume( long iVolume )								=	0;
	//ȡ����(0~100)
	virtual		bool	GetVolume( long& iVolume )								=	0;
	
	//������С����
	virtual		bool	SetMinDistance( float fValue )							=	0;
	//ȡ��С����
	virtual		bool	GetMinDistance( float& fValue )							=	0;
	
	//����������
	virtual		bool	SetMaxDistance( float fValue )							=	0;
	//ȡ������
	virtual		bool	GetMaxDistance( float& fValue )							=	0;
	
	//������Դλ��
	virtual		bool	SetSourcesPos( float fSourcesX, float fSourcesY, float fSourcesZ )	=	0;
	//ȡ��Դλ��
	virtual		bool	GetSourcesPos( float& fSourcesX, float& fSourcesY, float& fSourcesZ )	=	0;
	
	//�߼��ӿ�
	virtual		class	IAdvanceSound* QueryAdvance(void)						=	0;
};

//////////////////////////////////////////////////////////////////////
class ITqSoundManager
{
public:
	// ���ͷŽӿ�
	virtual		TQSRESULT	Release(void)										=	0;

	//��ʼ��
	virtual		bool	Init()													=	0;

	//���������ļ�������3DЧ�� // ������60s���ͷ�
	virtual		TQSRESULT	PlaySound(const char* lpszFileName, long nLoop=0, long nVolume=100)	=	0;

	//���������ļ�����3DЧ�� // ������60s���ͷ�
	virtual		TQSRESULT	Play3DSound( const char* lpszFileName, float fWorldX, float fWorldY, float fWorldZ,
																	float fMaxDistance=50,
																	long nLoop=0,long nVolume=100, bool bPlay=true ) =	0;

	//�������������ⲿ����ѭ������
	virtual		void	ProcessSound(void)										=	0;
	
	//�������������ļ��������ٷֱ�
	virtual		bool	SetVolume(long lPercent)								=	0;

	//ֹͣ���������ļ�
	virtual		bool	Stop(void)												=	0;

	//��������λ��
	virtual		void	SetListenerPos(float fX, float fY, float fZ)			=	0;
	//ȡ����λ��
	virtual		void	GetListenerPos(float& fX, float& fY, float& fZ)			=	0;
	
	//���������ٶ�
	virtual		void	SetListenerVel(float fX, float fY, float fZ)			=	0;
	//ȡ�����ٶ�
	virtual		void	GetListenerVel(float& fX, float& fY, float& fZ)			=	0;
	
	//���û��� dwValue �� enum Enum_ENVIRONMENT
	virtual		bool	SetEnvironment(ENVIRONMENT eValue)						=	0;

	//ȡ���� dwValue �� enum Enum_ENVIRONMENT
	virtual		bool	GetEnvironment(ENVIRONMENT& eValue)						=	0;

	//�����Թ������ �����겻�����ͷ� ��Ҫ���� ISound �� release �ͷ��Թ������ӿ�
	virtual		ISound*	CreateSound(const char* pszSoundName = NULL, int nLoop = 0, int nVolume = 100)			=	0;

	//////////////////////////////�߼�����///////////////////////////////////
	virtual		class	ITqAdvanceSoundManager*	QueryAdvanceSoundManager()		=	0;
};

/*TQSOUND_API*/ ITqSoundManager* TqSoundCreate();

//////////////////////////////////////////////////////////////////////
#endif  //#ifndef _ITQSOUND_H_2006_4_25_9_18




/********************************************************************
Created:		2006_4_25 9:18
Filename:		ITqSound.h
Author:		    lhq
Purpose:		
********************************************************************/
#ifndef _ITQSOUND_H_2006_4_25_9_18
#define _ITQSOUND_H_2006_4_25_9_18
//////////////////////////////////////////////////////////////////////
#ifdef TQSOUND_EXPORTS
#define TQSOUND_API __declspec(dllexport)
#else
#define TQSOUND_API __declspec(dllimport)
#endif

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
class ISound
{
public:
	// ���ͷŽӿ�
	virtual		TQSRESULT	Release(void)									=	0;

	//���������ļ�������3DЧ��
	virtual		TQSRESULT	PlaySound(const char* lpszFileName, LONG nLoop=0, LONG nVolume=100)	=	0;

	//���������ļ�����3DЧ��
	virtual		TQSRESULT	Play3DSound( const char* lpszFileName, FLOAT fWorldX, FLOAT fWorldY, FLOAT fWorldZ,
										FLOAT fMaxDistance=50, LONG nLoop=0, LONG nVolume=100, bool bPlay=true ) =	0;

	//���ڴ��в���������lpszFileName����������
	virtual		TQSRESULT PlaySoundByBuffer( const char* lpszFileName, const char* pBuffer, LONG lSize, LONG nLoop=0, LONG nVolume=100)	=	0;
	virtual		TQSRESULT Play3DSoundByBuffer( const char* lpszFileName, const char* pBuffer, LONG lSize, FLOAT fWorldX, FLOAT fWorldY, FLOAT fWorldZ,
										FLOAT fMaxDistance, LONG nLoop=0, LONG nVolume=100, bool bPlay=true )	=	0;

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
	virtual		bool	SetVolume( LONG iVolume )								=	0;
	//ȡ����(0~100)
	virtual		bool	GetVolume( LONG& iVolume )								=	0;
	
	//������С����
	virtual		bool	SetMinDistance( FLOAT fValue )							=	0;
	//ȡ��С����
	virtual		bool	GetMinDistance( FLOAT& fValue )							=	0;
	
	//����������
	virtual		bool	SetMaxDistance( FLOAT fValue )							=	0;
	//ȡ������
	virtual		bool	GetMaxDistance( FLOAT& fValue )							=	0;
	
	//������Դλ��
	virtual		bool	SetSourcesPos( FLOAT fSourcesX, FLOAT fSourcesY, FLOAT fSourcesZ )	=	0;
	//ȡ��Դλ��
	virtual		bool	GetSourcesPos( FLOAT& fSourcesX, FLOAT& fSourcesY, FLOAT& fSourcesZ )	=	0;
	
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
	virtual		TQSRESULT	PlaySound(const char* lpszFileName, LONG nLoop=0, LONG nVolume=100)	=	0;

	//���������ļ�����3DЧ�� // ������60s���ͷ�
	virtual		TQSRESULT	Play3DSound( const char* lpszFileName, FLOAT fWorldX, FLOAT fWorldY, FLOAT fWorldZ,
																	FLOAT fMaxDistance=50,
																	LONG nLoop=0,LONG nVolume=100, bool bPlay=true ) =	0;

	//�������������ⲿ����ѭ������
	virtual		void	ProcessSound(void)										=	0;
	
	//�������������ļ��������ٷֱ�
	virtual		bool	SetVolume(LONG lPercent)								=	0;

	//ֹͣ���������ļ�
	virtual		bool	Stop(void)												=	0;

	//��������λ��
	virtual		void	SetListenerPos(FLOAT fX, FLOAT fY, FLOAT fZ)			=	0;
	//ȡ����λ��
	virtual		void	GetListenerPos(FLOAT& fX, FLOAT& fY, FLOAT& fZ)			=	0;
	
	//���������ٶ�
	virtual		void	SetListenerVel(FLOAT fX, FLOAT fY, FLOAT fZ)			=	0;
	//ȡ�����ٶ�
	virtual		void	GetListenerVel(FLOAT& fX, FLOAT& fY, FLOAT& fZ)			=	0;
	
	//���û��� dwValue �� enum Enum_ENVIRONMENT
	virtual		bool	SetEnvironment(ENVIRONMENT eValue)						=	0;

	//ȡ���� dwValue �� enum Enum_ENVIRONMENT
	virtual		bool	GetEnvironment(ENVIRONMENT& eValue)						=	0;

	//�����Թ������ �����겻�����ͷ� ��Ҫ���� ISound �� release �ͷ��Թ������ӿ�
	virtual		ISound*	CreateSound(const char* pszSoundName = NULL, int nLoop = 0, int nVolume = 100)			=	0;

	//////////////////////////////�߼�����///////////////////////////////////
	virtual		class	ITqAdvanceSoundManager*	QueryAdvanceSoundManager()		=	0;
};

TQSOUND_API ITqSoundManager* TqSoundCreate();


//////////////////////////////////////////////////////////////////////
////////////////////////////�߼�����//////////////////////////////////
#ifndef TQSOUND_EXPORTS

typedef struct _EAXBUFFERPROPERTIES
{
	LONG lDirect;					// direct path level
	LONG lDirectHF;					// direct path level at high frequencies
	LONG lRoom;						// room effect level
	LONG lRoomHF;					// room effect level at high frequencies
	FLOAT flRoomRolloffFactor;		// like DS3D flRolloffFactor but for room effect
	LONG lObstruction;				// main obstruction control (attenuation at high frequencies) 
	FLOAT flObstructionLFRatio;		// obstruction low-frequency level re. main control
	LONG lOcclusion;				// main occlusion control (attenuation at high frequencies)
	FLOAT flOcclusionLFRatio;		// occlusion low-frequency level re. main control
	FLOAT flOcclusionRoomRatio;		// occlusion room effect level re. main control
	LONG lOutsideVolumeHF;			// outside sound cone level at high frequencies
	FLOAT flAirAbsorptionFactor;	// multiplies DSPROPERTY_EAXLISTENER_AIRABSORPTIONHF
	ULONG dwFlags;					// modifies the behavior of properties
} EAXBUFFERPROPERTIES, *LPEAXBUFFERPROPERTIES;

typedef struct _EAXLISTENERPROPERTIES
{
	LONG lRoom;						// room effect level at low frequencies
	LONG lRoomHF;					// room effect high-frequency level re. low frequency level
	FLOAT flRoomRolloffFactor;		// like DS3D flRolloffFactor but for room effect
	FLOAT flDecayTime;				// reverberation decay time at low frequencies
	FLOAT flDecayHFRatio;			// high-frequency to low-frequency decay time ratio
	LONG lReflections;				// early reflections level relative to room effect
	FLOAT flReflectionsDelay;		// initial reflection delay time
	LONG lReverb;					// late reverberation level relative to room effect
	FLOAT flReverbDelay;			// late reverberation delay time relative to initial reflection
	ULONG dwEnvironment;			// sets all listener properties
	FLOAT flEnvironmentSize;		// environment size in meters
	FLOAT flEnvironmentDiffusion;	// environment diffusion
	FLOAT flAirAbsorptionHF;		// change in level per meter at 5 kHz
	ULONG dwFlags;					// modifies the behavior of properties
} EAXLISTENERPROPERTIES, *LPEAXLISTENERPROPERTIES;

#endif//#ifndef TQSOUND_EXPORTS

class IAdvanceSound
{
public:
	//������Դ����
	virtual		bool	SetSourceDir( FLOAT fX, FLOAT fY, FLOAT fZ )	=	0;
	//ȡ��Դ����
	virtual		bool	GetSourceDir( FLOAT& fX, FLOAT& fY, FLOAT& fZ )	=	0;
	
	//������Դ�ٶ�
	virtual		bool	SetSourcesVel( FLOAT fX, FLOAT fY, FLOAT fZ )	=	0;
	//ȡ��Դ�ٶ�
	virtual		bool	GetSourcesVel( FLOAT& fX, FLOAT& fY, FLOAT& fZ )	=	0;
	
	//������Դ����
	virtual		bool	SetConeOrientation( FLOAT fDirX, FLOAT fDirY, FLOAT fDirZ )	=	0;
	//ȡ��Դ����
	virtual		bool	GetConeOrientation( FLOAT& fDirX, FLOAT& fDirY, FLOAT& fDirZ )	=	0;

	virtual		bool	SetConeInsideAngle( DWORD dwValue )				=	0;
	virtual		bool	GetConeInsideAngle( DWORD& dwValue )			=	0;

	virtual		bool	SetConeOutsideAngle( DWORD dwValue )			=	0;
	virtual		bool	GetConeOutsideAngle( DWORD& dwValue )			=	0;

	virtual		bool	SetConeOutsideVolume( FLOAT fValue )			=	0;
	virtual		bool	GetConeOutsideVolume( FLOAT& fValue )			=	0;
	
	
	////////////////////////////������Ч���//////////////////////////////////
	/*************************************************************************
	���ܣ�һ�θ㶨���еĲ��� �� LPEAXBUFFERPROPERTIES 
	*************************************************************************/
	virtual		bool	SetSourceAll( LPEAXBUFFERPROPERTIES lpData )	=	0;
	virtual		bool	GetSourceAll( LPEAXBUFFERPROPERTIES lpData )	=	0;
	
	virtual		bool	SetSourceDirect( LONG lValue )					=	0;
	virtual		bool	GetSourceDirect( LONG& lValue )					=	0;

	virtual		bool	SetSourceDirectHF( LONG lValue )				=	0;
	virtual		bool	GetSourceDirectHF( LONG& lValue )				=	0;

	virtual		bool	SetSourceRoom( LONG lValue )					=	0;
	virtual		bool	GetSourceRoom( LONG& lValue )					=	0;

	virtual		bool	SetSourceRoomHF( LONG lValue )					=	0;
	virtual		bool	GetSourceRoomHF( LONG& lValue )					=	0;

	virtual		bool	SetSourceRolloff( FLOAT fValue )				=	0;
	virtual		bool	GetSourceRolloff( FLOAT& fValue )				=	0;

	virtual		bool	SetSourceOutside( LONG lValue )					=	0;
	virtual		bool	GetSourceOutside( LONG& lValue )				=	0;
	
	virtual		bool	SetSourceAbsorption( FLOAT fValue )				=	0;
	virtual		bool	GetSourceAbsorption( FLOAT& fValue )			=	0;

	virtual		bool	SetSourceFlags( DWORD dwValue )					=	0;
	virtual		bool	GetSourceFlags( DWORD& dwValue )				=	0;

	virtual		bool	SetSourceObstruction( LONG lValue )				=	0;
	virtual		bool	GetSourceObstruction( LONG& lValue )			=	0;

	virtual		bool	SetSourceObstructionLF( FLOAT fValue )			=	0;
	virtual		bool	GetSourceObstructionLF( FLOAT& fValue )			=	0;

	virtual		bool	SetSourceOcclusion( LONG lValue )				=	0;
	virtual		bool	GetSourceOcclusion( LONG& lValue )				=	0;

	virtual		bool	SetSourceOcclusionLF( FLOAT fValue )			=	0;
	virtual		bool	GetSourceOcclusionLF( FLOAT& fValue )			=	0;

	virtual		bool	SetSourceOcclusionRoom( FLOAT fValue )			=	0;
	virtual		bool	GetSourceOcclusionRoom( FLOAT& fValue )			=	0;
	//////////////////////////////////////////////////////////////////////
};

	//////////////////////////////�߼�����////////////////////////////////////
class ITqAdvanceSoundManager
{
public:
	/*************************************************************************
	���ܣ�һ�θ㶨���еĲ��� �� LPEAXLISTENERPROPERTIES
	*************************************************************************/
	virtual		bool	SetAll( LPEAXLISTENERPROPERTIES lpData )		=	0;
	virtual		bool	GetAll( LPEAXLISTENERPROPERTIES lpData )		=	0;
	
	/*************************************************************************
	���ܣ���������Ч���ռ�Ĵ�С
	*************************************************************************/
	virtual		bool	SetRoom( LONG lValue )							=	0;
	virtual		bool	GetRoom( LONG& lValue )							=	0;
	
	/*************************************************************************
	���ܣ����÷����Ƶ�������
	˵��������ʹ���䡢ɢ���ø�Ƶ���棬����ͨ��˵��������ʪ����������ֱָ������
			ʪ��ָ�������ش����ĸߵ�Ƶ���棬������ֻ���ṩ�˸�Ƶ����Ŀ��ơ�
	*************************************************************************/
	virtual		bool	SetRoomHF( LONG lValue )						=	0;
	virtual		bool	GetRoomHF( LONG& lValue )						=	0;
	
	/*************************************************************************
	���ܣ������Ƶ����ϵ������
	˵��������ģ��ǽ������������ա�ʵ���У���Ƶ����������ά�ȿ��Ե�����
		һ���˲���˥����ȣ�������Ƶ�������ʣ�һ�����˲����Ľ�ֹƵ�ʣ�
		������������Ƶ�����ԡ�������һ���������������ά�ȵ�������ת��Ƶ�ʸ�ʱ��
		�����ٶȶ��ô�һЩ��ת��Ƶ�ʵ�ʱ�������ٶȾͿ���СһЩ��
		������������Ч���Ż���Ȼ��
	*************************************************************************/
	virtual		bool	SetRoomRolloff( FLOAT fValue )					=	0;
	virtual		bool	GetRoomRolloff( FLOAT& fValue )					=	0;
	
	/*************************************************************************
	���ܣ�������Ƶ����
	˵��������ģ������Ը�Ƶ�������������ԡ�����ʪ��Խ�󣬶������ĸ�Ƶ������Խ�͡�
	*************************************************************************/
	virtual		bool	SetAirAbsorption( FLOAT fValue )				=	0;
	virtual		bool	GetAirAbsorption( FLOAT& fValue )				=	0;
	
	/*************************************************************************
	���ܣ����߸�Ƶ����ϵ������
	˵��������ģ�����߶����������Ĳ�ͬӰ�죬��������ǰ��
		�����˶��Ĺ���������������������������ѹ�ֵġ�ͬ�����Ƶ����ϵ��һ����
		�����������γ�ȵ�������֧��EAX��3D��Ϸ�У�
		��Ч��3D��λʵ��������Direct Sound 3D����ɵġ�
	*************************************************************************/
	virtual		bool	SetListenerRolloff( FLOAT fValue )				=	0;
	virtual		bool	GetListenerRolloff( FLOAT& fValue )				=	0;
	
	/*************************************************************************
	���ܣ�˥��ʱ������
	˵������Ի���Ч��������ʧ���ԣ�����Ϊ��λ��С�������Ϊ����
	*************************************************************************/
	virtual		bool	SetDecayTime( FLOAT fValue )					=	0;
	virtual		bool	GetDecayTime( FLOAT& fValue )					=	0;
	
	/*************************************************************************
	���ܣ�˥����Ƶ��������
	˵��������ֱָ����������źŵı��ʣ�������ǿ������������Ȼ���ԡ�
	*************************************************************************/
	virtual		bool	SetDecayHFRatio( FLOAT fValue )					=	0;
	virtual		bool	GetDecayHFRatio( FLOAT& fValue )				=	0;
	
	/*************************************************************************
	���ܣ�������������
	˵�����ṩ���ڷ���ͻ����Ķ�λ��ϵ��Խ�󣬷���Խ��
	*************************************************************************/
	virtual		bool	SetReflections( LONG lValue )					=	0;
	virtual		bool	GetReflections( LONG& lValue )					=	0;
	
	/*************************************************************************
	���ܣ�������ʱ����
	˵���������ӳ�ʱ��Խ�󣬷������Ч��Խ���ԡ�С��������Ժ���Ϊ��λ��
	*************************************************************************/
	virtual		bool	SetReflectionsDelay( FLOAT fValue )				=	0;
	virtual		bool	GetReflectionsDelay( FLOAT& fValue )			=	0;
	
	/*************************************************************************
	���ܣ����������С����
	˵����������ֹͣ���������ڷ����ڴ����������棬
		ʹ����������η����ɢ����γɵ��������������Ϊ���졣
	*************************************************************************/
	virtual		bool	SetReverb( LONG lValue )						=	0;
	virtual		bool	GetReverb( LONG& lValue )						=	0;
	
	/*************************************************************************
	���ܣ��������ӳ�ʱ������
	˵��������ģ�����������ӳ�ЧӦ���϶�����������ӳ�ʱ�䡣
		��Щ���������ζ�Ӧ������Ϊ����ռ�ߴ������SIZE����
		ʵ�������ڵ������������ܶȣ����ӳ�ʱ��Խ��������������ܶȾ�Խϡ�裬
		ģ��Ļ���ռ�ߴ�Խ��
	*************************************************************************/
	virtual		bool	SetReverbDelay( FLOAT fValue )					=	0;
	virtual		bool	GetReverbDelay( FLOAT& fValue )					=	0;
	
	/*************************************************************************
	���ܣ����û���(�ռ�)��С���ߴ硣
	˵����¼��������Ϊģ����Ȼ���������û����ҹ������͵ĸߵ�¼����ϵͳ��
		�����ҵ����һ��ȡ100�����׻��С�����ӳ�ʱ��Խ�󣬻����ܶ�Խϡ�裬
		����ռ�Խ��
	*************************************************************************/
	virtual		bool	SetEnvironmentSize( FLOAT fValue )				=	0;
	virtual		bool	GetEnvironmentSize( FLOAT& fValue )				=	0;
	
	/*************************************************************************
	���ܣ�������ɢ
	˵������������ϵ��������ȷ������������ܶ������ʡ�
	*************************************************************************/
	virtual		bool	SetEnvironmentDiffusion( FLOAT fValue )			=	0;
	virtual		bool	GetEnvironmentDiffusion( FLOAT& fValue )		=	0;
	
	virtual		bool	SetFlags( DWORD dwValue )						=	0;
	virtual		bool	GetFlags( DWORD& dwValue )						=	0;
	
	/*************************************************************************
	���ܣ�˥��ʱ������
	˵������ʱ���壬�����޷���֪Ч��
	*************************************************************************/
	virtual		bool	SetScaleDecayTime( bool bValue )				=	0;
	virtual		bool	GetScaleDecayTime( bool& bValue )				=	0;
	
	/*************************************************************************
	���ܣ���������
	˵������ʱ���壬�����޷���֪Ч��
	*************************************************************************/
	virtual		bool	SetScaleReflections( bool bValue )				=	0;
	virtual		bool	GetScaleReflections( bool& bValue )				=	0;
	
	/*************************************************************************
	���ܣ������ӳ�ʱ������
	˵������ʱ���壬�����޷���֪Ч��
	*************************************************************************/
	virtual		bool	SetScaleReflectionsDelay( bool bValue )			=	0;
	virtual		bool	GetScaleReflectionsDelay( bool& bValue )		=	0;
	
	/*************************************************************************
	���ܣ������С����
	˵������ʱ���壬�����޷���֪Ч��
	*************************************************************************/
	virtual		bool	SetScaleReverb( bool bValue )					=	0;
	virtual		bool	GetScaleReverb( bool& bValue )					=	0;
	
	/*************************************************************************
	���ܣ������ӳ�ʱ������
	˵������ʱ���壬�����޷���֪Ч��
	*************************************************************************/
	virtual		bool	SetScaleReverbDelay( bool bValue )				=	0;
	virtual		bool	GetScaleReverbDelay( bool& bValue )				=	0;
	
	/*************************************************************************
	���ܣ���Ƶ˥���г�
	˵������˥�������У���Դͷǰ�Ļ����źŻ��ܵ��������ڱ�Ӱ�죬
		ͨ����ѡ������Ҫ��ʱ���жϺ�����
	*************************************************************************/
	virtual		bool	SetClipDecayHF( bool bValue )					=	0;
	virtual		bool	GetClipDecayHF( bool& bValue )					=	0;
	
	//////////////////////////////////////////////////////////////////////
};

//////////////////////////////////////////////////////////////////////
#endif  //#ifndef _ITQSOUND_H_2006_4_25_9_18




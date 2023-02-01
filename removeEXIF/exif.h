#ifndef AIEXIFHEADER
#define AIEXIFHEADER

#define JPEG_SOI_TAG			0xD8FF
#define EXIF_TAG				0xFFE1

#define INTEL					0x4949
#define L_ENDIAN				INTEL
#define MOTOROLLA				0x4D4D
#define B_ENDIAN				MOTOROLLA

#define SIZE_OF_SOI_MARKER		2
#define SIZE_OF_APP1_MARKER		2
#define SIZE_OF_DEFAULT_HEADER	18
#define SIZE_OF_TIFF_HEADER		12

typedef unsigned char			BYTE;
typedef char					SBYTE;
typedef unsigned short			SHORT;
typedef short					SSHORT;
typedef unsigned int			LONG;
typedef int						SLONG;
typedef char* UNDEFINED;
typedef char* ASCII;

enum IFDs
{
	IFD0th = 1,
	Inter,
	Exif,
	GPS,
	IFD1st
};

enum {
	TYPE_BYTE = 1,
	TYPE_ASCII,
	TYPE_SHORT,
	TYPE_LONG,
	TYPE_RATIONAL,
	TYPE_SBYTE,
	TYPE_UNDEFINED,
	TYPE_SSHORT,
	TYPE_SLONG,
	TYPE_SRATIONAL
};

typedef struct RATIONAL_s {
	LONG nominator;
	LONG denominator;
} RATIONAL;

typedef struct SRATIONAL_s {
	SLONG nominator;
	SLONG denominator;
} SRATIONAL;

#pragma pack(push, 1)
struct TIFF_header_s {
	SHORT byteOrder;
	SHORT reserved;
	LONG Ifd0thOffset;
};
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct APP1Header_s {
	SHORT	marker;
	SHORT	count;
	BYTE	EXIF[6];
	struct TIFF_header_s
		tiff_header;
} APP1Header;
#pragma pack(pop)

#pragma pack(push, 1)
typedef struct Tag_s {
	SHORT tag;
	SHORT type;
	LONG  count;
	BYTE* ptr;
} Tag;
#pragma pack(pop)

#define ImageWidth                  0x0100
#define ImageLength                 0x0101
#define BitsPerSample               0x0102
#define Compression                 0x0103
#define PhotometricInterpretation   0x0106
#define Orientation                 0x0112
#define SamplesPerPixel             0x0115
#define PlanarConfiguration         0x011C
#define YCbCrSubSampling            0x0212
#define YCbCrPositioning            0x0213
#define XResolution                 0x011A
#define YResolution                 0x011B
#define ResolutionUnit              0x0128
#define StripOffsets                0x0111
#define RowsPerStrip                0x0116
#define StripByteCounts             0x0117
#define JPEGInterchangeFormat       0x0201
#define JPEGInterchangeFormatLength 0x0202
#define TransferFunction            0x012D
#define WhitePoint                  0x013E
#define PrimaryChromaticities       0x013F
#define YCbCrCoefficients           0x0211
#define ReferenceBlackWhite         0x0214
#define DateTime                    0x0132
#define ImageDescription            0x010E
#define Make                        0x010F
#define Model                       0x0110
#define Software                    0x0131
#define Artist                      0x013B
#define Copyright                   0x8298
#define ExifIFDPointer              0x8769
#define GPSInfoIFDPointer           0x8825
#define InteroperabilityIFDPointer  0xA005
#define Rating                      0x4746
#define ExifVersion                 0x9000
#define FlashPixVersion             0xA000
#define ColorSpace                  0xA001
#define ComponentsConfiguration     0x9101
#define CompressedBitsPerPixel      0x9102
#define PixelXDimension             0xA002
#define PixelYDimension             0xA003
#define MakerNote                   0x927C
#define UserComment                 0x9286
#define RelatedSoundFile            0xA004
#define DateTimeOriginal            0x9003
#define DateTimeDigitized           0x9004
#define SubSecTime                  0x9290
#define SubSecTimeOriginal          0x9291
#define SubSecTimeDigitized         0x9292
#define ExposureTime                0x829A
#define FNumber                     0x829D
#define ExposureProgram             0x8822
#define SpectralSensitivity         0x8824
#define PhotographicSensitivity     0x8827
#define OECF                        0x8828
#define SensitivityType             0x8830
#define StandardOutputSensitivity   0x8831
#define RecommendedExposureIndex    0x8832
#define ISOSpeed                    0x8833
#define ISOSpeedLatitudeyyy         0x8834
#define ISOSpeedLatitudezzz         0x8835
#define ShutterSpeedValue           0x9201
#define ApertureValue               0x9202
#define BrightnessValue             0x9203
#define ExposureBiasValue           0x9204
#define MaxApertureValue            0x9205
#define SubjectDistance             0x9206
#define MeteringMode                0x9207
#define LightSource                 0x9208
#define Flash                       0x9209
#define FocalLength                 0x920A
#define SubjectArea                 0x9214
#define FlashEnergy                 0xA20B
#define SpatialFrequencyResponse    0xA20C
#define FocalPlaneXResolution       0xA20E
#define FocalPlaneYResolution       0xA20F
#define FocalPlaneResolutionUnit    0xA210
#define SubjectLocation             0xA214
#define ExposureIndex               0xA215
#define SensingMethod               0xA217
#define FileSource                  0xA300
#define SceneType                   0xA301
#define CFAPattern					0xA302
#define CustomRendered              0xA401
#define ExposureMode                0xA402
#define WhiteBalance                0xA403
#define DigitalZoomRatio            0xA404
#define FocalLengthIn35mmFormat     0xA405
#define SceneCaptureType            0xA406
#define GainControl                 0xA407
#define Contrast                    0xA408
#define Saturation                  0xA409
#define Sharpness                   0xA40A
#define DeviceSettingDescription    0xA40B
#define SubjectDistanceRange        0xA40C
#define ImageUniqueID               0xA420
#define CameraOwnerName             0xA430
#define BodySerialNumber            0xA431
#define LensSpecification           0xA432
#define LensMake                    0xA433
#define LensModel                   0xA434
#define LensSerialNumber            0xA435
#define Gamma                       0xA500
#define GPSVersionID				0x0000
#define GPSLatitudeRef				0x0001
#define GPSLatitude					0x0002
#define GPSLongitudeRef				0x0003
#define GPSLongitude				0x0004
#define GPSAltitudeRef				0x0005
#define GPSAltitude					0x0006
#define GPSTimeStamp				0x0007
#define GPSSatellites				0x0008
#define GPSStatus					0x0009
#define GPSMeasureMode				0x000A
#define GPSDOP						0x000B
#define GPSSpeedRef					0x000C
#define GPSSpeed					0x000D
#define GPSTrackRef					0x000E
#define GPSTrack					0x000F
#define GPSImgDirectionRef			0x0010
#define GPSImgDirection				0x0011
#define GPSMapDatum					0x0012
#define GPSDestLatitudeRef			0x0013
#define GPSDestLatitude				0x0014
#define GPSDestLongitudeRef			0x0015
#define GPSDestLongitude			0x0016
#define GPSBearingRef				0x0017
#define GPSBearing					0x0018
#define GPSDestDistanceRef			0x0019
#define GPSDestDistance				0x001A
#define GPSProcessingMethod			0x001B
#define GPSAreaInformation			0x001C
#define GPSDateStamp				0x001D
#define GPSDifferential				0x001E
#define GPSHPositioningError		0x001F

#endif


#ifndef __7ZIP_COMPRESS_CODECS_INFO_H__
#define __7ZIP_COMPRESS_CODECS_INFO_H__

class C7ZipCompressCodecsInfo : public ICompressCodecsInfo,
    public CMyUnknownImp,
    public virtual C7ZipObject
{
public:
    C7ZipCompressCodecsInfo(C7ZipLibrary * pLibrary);
    virtual ~C7ZipCompressCodecsInfo();

    Z7_COM_UNKNOWN_IMP_1(ICompressCodecsInfo)

#if MY_VER_MAJOR >= 15
    STDMETHOD(GetNumMethods)(UInt32 *numMethods) throw() override;
#else    
    STDMETHOD(GetNumberOfMethods)(UInt32 *numMethods) throw() override;
#endif	
    STDMETHOD(GetProperty)(UInt32 index, PROPID propID, PROPVARIANT *value) throw() override;
    STDMETHOD(CreateDecoder)(UInt32 index, const GUID *interfaceID, void **coder) throw() override;
    STDMETHOD(CreateEncoder)(UInt32 index, const GUID *interfaceID, void **coder) throw() override;

    void InitData();
private:
    C7ZipLibrary * m_pLibrary;
    C7ZipObjectPtrArray m_CodecInfoArray;
};

#endif //__7ZIP_COMPRESS_CODECS_INFO_H__


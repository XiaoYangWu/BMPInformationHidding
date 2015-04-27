// ImageDib.h: interface for the ImageDib class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_IMAGEDIB_H__61C6D3D9_025D_4D6B_9FF1_2609814372DA__INCLUDED_)
#define AFX_IMAGEDIB_H__61C6D3D9_025D_4D6B_9FF1_2609814372DA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class ImageDib  
{
public:
	unsigned char * m_pImgData;
	LPRGBQUAD m_lpColorTable;
	int m_nBitCount;
private:
	LPBYTE m_lpDib;
	HPALETTE m_hPalette;
	int m_nColorTableLength;
public:
	int m_imgWidth;
	int m_imgHeight;
	LPBITMAPINFOHEADER m_lpBmpInfoHead;
public:
	BITMAPFILEHEADER bmfh;
	ImageDib();
	virtual ~ImageDib();
	BOOL Read(LPCTSTR lpszPathName);
	BOOL Write(LPCTSTR lpszPathName);
	int ComputeColorTabalLength(int nBitCount);
	BOOL Draw(CDC* pDC,CPoint origin,CSize size);
	CSize GetDimensions();
	void ReplaceDib(CSize size,int nBitCount,LPRGBQUAD lpColorTable,unsigned char *pImgData);
private:
	void MakePalette();
	void Empty();

};

#endif // !defined(AFX_IMAGEDIB_H__61C6D3D9_025D_4D6B_9FF1_2609814372DA__INCLUDED_)

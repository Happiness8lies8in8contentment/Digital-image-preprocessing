
// jcshiliDlg.h : 头文件
//

#pragma once
#include <opencv2/opencv.hpp>
#include <iostream>
#include "d:\opencv3\opencv\build\include\opencv2\core\mat.hpp"
#include "d:\opencv3\opencv\build\include\opencv2\core\mat.hpp"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "d:\opencv3\opencv\build\include\opencv2\core\mat.hpp"
#include "d:\opencv3\opencv\build\include\opencv2\core\mat.hpp"
#include "d:\opencv3\opencv\build\include\opencv2\core\mat.hpp"
#include "d:\opencv3\opencv\build\include\opencv2\core\mat.hpp"
#include "d:\opencv3\opencv\build\include\opencv2\core\mat.hpp"
#include "afxcmn.h"
#include "afxwin.h"
#include "MFCClass.h"
#include "SXBtn.h"
#include "BtnST.h"

using namespace cv;
using namespace std;

// CjcshiliDlg 对话框
class CjcshiliDlg : public CDialogEx
{
// 构造
public:
	CjcshiliDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_JCSHILI_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickopenImage();
	Mat m_srcImg;
	void ShowImage(Mat& img ,int nID);
	afx_msg void OnBnClicksaveImage();
	Mat outimage;
	int g_nFangKuanValue;
	int g_nJunZhiValue;
	int g_nGaoSiValue;
	int g_nZhongZhiValue;
	int g_nShuangZhiValue;
	int g_nCloseNum;
	int g_nDilateNum;
	int g_nTopHatNum;
	int g_nOpenNum;
	int g_nErodeNum;
	int g_nBlackHatNum;
	int g_nMaxIterationNum;
	int g_nElementShape;
	int g_nContrastValue,g_nBrightValue;
	Mat g_dstImage1;
	Mat g_dstImage2;
	Mat g_dstImage3;
	Mat g_dstImage4;
	Mat g_dstImage5;
	Mat g_dstImage6;
	Mat g_dstImage7;
	Mat g_dstImage8;
	Mat g_dstImage9;
	Mat g_dstImage10;
	Mat g_dstImage11;
	Mat g_srcGrayImage,g_dstImage12,g_dstImage13,g_dstImage14;
	Mat g_dstImage15,g_dstImage16,g_dstImage17,g_dstImage18,g_dstImage19;
	Mat g_map_x,g_map_y;

	Mat g_cannyDetectedEdges;
	int g_cannyLowThreshold;

	Mat g_sobelGradient_x,g_sobelGradient_y;
	Mat g_sobelAbsGradient_x,g_sobelAbsGradient_y;
	int g_sobelKernelSize;

	Mat g_scharrGradient_x,g_scharrGradient_y;
	Mat g_scharrAbsGradient_x,g_scharrAbsGradient_y;

	afx_msg void OnBnClickedFankuang();
	
	afx_msg void OnBnClickedJunzhi();
	afx_msg void OnBnClickedGaosi();
	afx_msg void OnBnClickedZhongzhi();
	afx_msg void OnBnClickedShuangbian();
	afx_msg void OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	int m_int;
	CSliderCtrl m_slider;
	afx_msg void OnBnClickedFushi();
	afx_msg void OnBnClickedPengzhang();
	afx_msg void OnBnClickedKaiyunsuan();
	afx_msg void OnBnClickedBiyunsuan();
	afx_msg void OnBnClickedDingmao();
	afx_msg void OnBnClickedHeimao();
	afx_msg void OnBnClickedJiance();
	afx_msg void OnBnClickedCannyjiance();
	afx_msg void OnBnClickedSobeljiance();
	afx_msg void OnBnClickedScharrjiance();
//	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	
private:
	CBrush m_brush;
public:
	CButtonST m_btnTest;
	CButtonST m_btnST;
	CButtonST m_kaiyunsuan;
	CButtonST biyunsuan;
	CButtonST m_dingmao;
	CButtonST m_heimao;
	CButtonST m_jiance;
	CButtonST m_baocun;
	CButtonST m_shuangbian;
	CButtonST m_zhongzhi;
	CButtonST m_gaosi;
	CButtonST m_junzhi;
	CButtonST m_fangkuang;
	CButtonST m_dakai;
	CButtonST m_canny;
	CButtonST m_sobel;
	CButtonST m_schar;
	afx_msg void OnBnClickedFistchong();
	afx_msg void OnBnClickedTwochong();
	afx_msg void OnBnClickedTreechong();
	afx_msg void OnBnClickedFourchong();
	afx_msg void OnBnClickedLightbuchang();
	afx_msg void OnBnClickedHuiduhua();
	afx_msg void OnBnClickedErzhihua();
	afx_msg void OnBnClickedZhifangtu();
	afx_msg void OnBnClickedQuchugulidian();
};

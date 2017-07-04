
// jcshiliDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "jcshili.h"
#include "jcshiliDlg.h"
#include "afxdialogex.h"
#include "SXBtn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CjcshiliDlg 对话框




CjcshiliDlg::CjcshiliDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CjcshiliDlg::IDD, pParent)
	, g_nFangKuanValue(0)
	, g_nJunZhiValue(0)
	, g_nGaoSiValue(0)
	, g_nZhongZhiValue(0)
	, g_nShuangZhiValue(0)
	, m_int(0)
	
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	g_nFangKuanValue=6;
	g_nGaoSiValue=6;
	g_nJunZhiValue=10;
	g_nZhongZhiValue=10;
	g_nShuangZhiValue=10;
	g_nCloseNum=9;
	g_nDilateNum=9;
	g_nTopHatNum=2;
	g_nOpenNum=9;
	g_nErodeNum=9;
	g_nBlackHatNum=2;
	g_nMaxIterationNum=0;
	g_nElementShape=MORPH_RECT;
	g_cannyLowThreshold=1;
	g_sobelKernelSize=1;
	g_nBrightValue=80;
	g_nContrastValue=80;
	
}

void CjcshiliDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER3, m_slider);
	DDX_Control(pDX, IDC_SLIDER3, m_slider);
	DDX_Control(pDX, IDC_FUSHI, m_btnTest);
	DDX_Control(pDX, IDC_PENGZHANG, m_btnST);
	DDX_Control(pDX, IDC_KAIYUNSUAN, m_kaiyunsuan);
	DDX_Control(pDX, IDC_BIYUNSUAN, biyunsuan);
	DDX_Control(pDX, IDC_DINGMAO, m_dingmao);
	DDX_Control(pDX, IDC_HEIMAO, m_heimao);
	DDX_Control(pDX, IDC_JIANCE, m_jiance);
	DDX_Control(pDX, IDC_SAVEIMAGE, m_baocun);
	DDX_Control(pDX, IDC_SHUANGBIAN, m_shuangbian);
	DDX_Control(pDX, IDC_ZHONGZHI, m_zhongzhi);
	DDX_Control(pDX, IDC_GAOSI, m_gaosi);
	DDX_Control(pDX, IDC_JUNZHI, m_junzhi);
	DDX_Control(pDX, IDC_FANKUANG, m_fangkuang);
	DDX_Control(pDX, IDC_OPENIMAGE, m_dakai);
	DDX_Control(pDX, IDC_CANNYJIANCE, m_canny);
	DDX_Control(pDX, IDC_SOBELJIANCE, m_sobel);
	DDX_Control(pDX, IDC_SCHARRJIANCE, m_schar);
}

BEGIN_MESSAGE_MAP(CjcshiliDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_OPENIMAGE, &CjcshiliDlg::OnBnClickopenImage)
	
	
	ON_BN_CLICKED(IDC_SAVEIMAGE, &CjcshiliDlg::OnBnClicksaveImage)
	ON_BN_CLICKED(IDC_FANKUANG, &CjcshiliDlg::OnBnClickedFankuang)
	ON_BN_CLICKED(IDC_JUNZHI, &CjcshiliDlg::OnBnClickedJunzhi)
	ON_BN_CLICKED(IDC_GAOSI, &CjcshiliDlg::OnBnClickedGaosi)
	ON_BN_CLICKED(IDC_ZHONGZHI, &CjcshiliDlg::OnBnClickedZhongzhi)
	ON_BN_CLICKED(IDC_SHUANGBIAN, &CjcshiliDlg::OnBnClickedShuangbian)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_SLIDER3, &CjcshiliDlg::OnNMCustomdrawSlider3)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_FUSHI, &CjcshiliDlg::OnBnClickedFushi)
	ON_BN_CLICKED(IDC_PENGZHANG, &CjcshiliDlg::OnBnClickedPengzhang)
	ON_BN_CLICKED(IDC_KAIYUNSUAN, &CjcshiliDlg::OnBnClickedKaiyunsuan)
	ON_BN_CLICKED(IDC_BIYUNSUAN, &CjcshiliDlg::OnBnClickedBiyunsuan)
	ON_BN_CLICKED(IDC_DINGMAO, &CjcshiliDlg::OnBnClickedDingmao)
	ON_BN_CLICKED(IDC_HEIMAO, &CjcshiliDlg::OnBnClickedHeimao)
	ON_BN_CLICKED(IDC_JIANCE, &CjcshiliDlg::OnBnClickedJiance)
	ON_BN_CLICKED(IDC_CANNYJIANCE, &CjcshiliDlg::OnBnClickedCannyjiance)
	ON_BN_CLICKED(IDC_SOBELJIANCE, &CjcshiliDlg::OnBnClickedSobeljiance)
	ON_BN_CLICKED(IDC_SCHARRJIANCE, &CjcshiliDlg::OnBnClickedScharrjiance)
//	ON_WM_CTLCOLOR()
ON_BN_CLICKED(IDC_FISTCHONG, &CjcshiliDlg::OnBnClickedFistchong)
ON_BN_CLICKED(IDC_TWOCHONG, &CjcshiliDlg::OnBnClickedTwochong)
ON_BN_CLICKED(IDC_TREECHONG, &CjcshiliDlg::OnBnClickedTreechong)
ON_BN_CLICKED(IDC_FOURCHONG, &CjcshiliDlg::OnBnClickedFourchong)
ON_BN_CLICKED(IDC_LIGHTBUCHANG, &CjcshiliDlg::OnBnClickedLightbuchang)
ON_BN_CLICKED(IDC_HUIDUHUA, &CjcshiliDlg::OnBnClickedHuiduhua)
ON_BN_CLICKED(IDC_ERZHIHUA, &CjcshiliDlg::OnBnClickedErzhihua)
ON_BN_CLICKED(IDC_ZHIFANGTU, &CjcshiliDlg::OnBnClickedZhifangtu)
ON_BN_CLICKED(IDC_QUCHUGULIDIAN, &CjcshiliDlg::OnBnClickedQuchugulidian)
END_MESSAGE_MAP()



// CjcshiliDlg 消息处理程序

BOOL CjcshiliDlg::OnInitDialog()
{

	m_btnST.SetActiveBgColor(RGB(0,0,255));
	m_btnST.SetActiveFgColor(RGB(255,0,0));
	m_btnST.SetInactiveBgColor(RGB(125,125,0));
	m_btnST.SetInactiveFgColor(RGB(255,125,12));
	m_btnTest.SetActiveBgColor(RGB(0,0,255));
	m_btnTest.SetActiveFgColor(RGB(255,0,0));
	m_btnTest.SetInactiveBgColor(RGB(125,125,0));
	m_btnTest.SetInactiveFgColor(RGB(255,125,12));
	m_kaiyunsuan.SetActiveBgColor(RGB(0,0,255));
	m_kaiyunsuan.SetActiveFgColor(RGB(255,0,0));
	m_kaiyunsuan.SetInactiveBgColor(RGB(125,125,0));
	m_kaiyunsuan.SetInactiveFgColor(RGB(255,125,12));
	biyunsuan.SetActiveBgColor(RGB(0,0,255));
	biyunsuan.SetActiveFgColor(RGB(255,0,0));
	biyunsuan.SetInactiveBgColor(RGB(125,125,0));
	biyunsuan.SetInactiveFgColor(RGB(255,125,12));
	m_dingmao.SetActiveBgColor(RGB(0,0,255));
	m_dingmao.SetActiveFgColor(RGB(255,0,0));
	m_dingmao.SetInactiveBgColor(RGB(125,125,0));
	m_dingmao.SetInactiveFgColor(RGB(255,125,12));
	m_heimao.SetActiveBgColor(RGB(0,0,255));
	m_heimao.SetActiveFgColor(RGB(255,0,0));
	m_heimao.SetInactiveBgColor(RGB(125,125,0));
	m_heimao.SetInactiveFgColor(RGB(255,125,12));
	m_jiance.SetActiveBgColor(RGB(0,0,255));
	m_jiance.SetActiveFgColor(RGB(255,0,0));
	m_jiance.SetInactiveBgColor(RGB(125,125,0));
	m_jiance.SetInactiveFgColor(RGB(255,125,12));
	m_baocun.SetActiveBgColor(RGB(0,0,255));
	m_baocun.SetActiveFgColor(RGB(255,0,0));
	m_baocun.SetInactiveBgColor(RGB(125,125,0));
	m_baocun.SetInactiveFgColor(RGB(255,125,12));
	m_shuangbian.SetActiveBgColor(RGB(0,0,255));
	m_shuangbian.SetActiveFgColor(RGB(255,0,0));
	m_shuangbian.SetInactiveBgColor(RGB(125,125,0));
	m_shuangbian.SetInactiveFgColor(RGB(255,125,12));
	m_zhongzhi.SetActiveBgColor(RGB(0,0,255));
	m_zhongzhi.SetActiveFgColor(RGB(255,0,0));
	m_zhongzhi.SetInactiveBgColor(RGB(125,125,0));
	m_zhongzhi.SetInactiveFgColor(RGB(255,125,12));
	m_gaosi.SetActiveBgColor(RGB(0,0,255));
	m_gaosi.SetActiveFgColor(RGB(255,0,0));
	m_gaosi.SetInactiveBgColor(RGB(125,125,0));
	m_gaosi.SetInactiveFgColor(RGB(255,125,12));
	m_junzhi.SetActiveBgColor(RGB(0,0,255));
	m_junzhi.SetActiveFgColor(RGB(255,0,0));
	m_junzhi.SetInactiveBgColor(RGB(125,125,0));
	m_junzhi.SetInactiveFgColor(RGB(255,125,12));
	m_fangkuang.SetActiveBgColor(RGB(0,0,255));
	m_fangkuang.SetActiveFgColor(RGB(255,0,0));
	m_fangkuang.SetInactiveBgColor(RGB(125,125,0));
	m_fangkuang.SetInactiveFgColor(RGB(255,125,12));
	m_dakai.SetActiveBgColor(RGB(0,0,255));
	m_dakai.SetActiveFgColor(RGB(255,0,0));
	m_dakai.SetInactiveBgColor(RGB(125,125,0));
	m_dakai.SetInactiveFgColor(RGB(255,125,12));
	m_canny.SetActiveBgColor(RGB(0,0,255));
	m_canny.SetActiveFgColor(RGB(255,0,0));
	m_canny.SetInactiveBgColor(RGB(125,125,0));
	m_canny.SetInactiveFgColor(RGB(255,125,12));
	m_sobel.SetActiveBgColor(RGB(0,0,255));
	m_sobel.SetActiveFgColor(RGB(255,0,0));
	m_sobel.SetInactiveBgColor(RGB(125,125,0));
	m_sobel.SetInactiveFgColor(RGB(255,125,12));
	m_schar.SetActiveBgColor(RGB(0,0,255));
	m_schar.SetActiveFgColor(RGB(255,0,0));
	m_schar.SetInactiveBgColor(RGB(125,125,0));
	m_schar.SetInactiveFgColor(RGB(255,125,12));
	
	
	CDialogEx::OnInitDialog();
	m_slider.SetRange(0,100);//设置滑动范围

	m_slider.SetTicFreq(10);//每10个单位画一刻度
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages shouldreturn FALSE

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CjcshiliDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CjcshiliDlg::OnPaint()
{


	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CjcshiliDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CjcshiliDlg::OnBnClickopenImage()
{
	// TODO: 在此添加控件通知处理程序代码
	CFileDialog dlg(TRUE,_T(".dmp"),_T("*.dmp"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("位图文件 (*.bmp)|*.bmp|JPEG文件 (*.jpg)|*.jpg|PNG文件 (*.png)|*.png||"));//选择图片
	if (IDOK==dlg.DoModal())//打开选择的图片
	{
		string filename=dlg.GetPathName();//获取图片的路径及文件名
		m_srcImg = imread(filename,CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);//将图片保存至全局变量theImage对象中
		if(!m_srcImg.data){printf("读取srcImage错误~！ \n");}
	}
	ShowImage(m_srcImg, IDC_YUANTU);
	
}


void CjcshiliDlg::ShowImage(Mat& img,int nID)
{ 
	CWnd* pimgShowCtrl = this->GetDlgItem(nID); //获得nID控件的句柄
	CRect ctrlRect;		//定义变量用以保存picture控件的大小
	pimgShowCtrl->GetClientRect(&ctrlRect); //获得picture控件的大小

	CDC* pDC = pimgShowCtrl->GetDC(); //获得设备上下文，因为后面显示函数的参数中需要它

	//初始化一个位图信息头
	BITMAPINFOHEADER BHEADER = {40, 0, 0, 1, 0, BI_RGB, 0, 0, 0, 0};

	//获得传入图像的相关信息（赋值给位图信息头）
	int width, height, depth, channel, width1;
	width = img.cols;
	height = img.rows;
	depth = img.depth();
	channel = img.channels();

	int bits, colors, i;
	bits = ( 8<< (depth/2) )*channel;//8左移0、1、2、3分别代表8、16、32、64，每个像素所占的位数
	if(bits > 8)
	{
		colors = 0;//真彩色位图没有颜色表
	}
	else
	{
		colors = ( 1<<bits );//非真彩色的位图有相应的颜色表
	}
	//当真彩色图像时，让每个像素占四个字节，这样就解决了真彩色图像的4字节边界对齐问题
	if (bits == 24)
	{
		bits = 32;
	}

	//给位图信息头赋值
	//当灰度图像时，由于每个像素占一个字节，所以让每行像素（即图像的宽度）进行4字节边界对齐
	if(bits == 8)
	{
		width1 = (width*8 + 31)/32 * 4; //4字节边界对齐后的图像的宽度
		BHEADER.biWidth = width1;
	}
	else
	{
		BHEADER.biWidth = width;//真彩色图像时，图像的像素宽度还是原来图像的像素宽度
	}
	BHEADER.biWidth = width;
	BHEADER.biHeight = height;			
	BHEADER.biBitCount = bits;

	LPBITMAPINFO lpBitsInfo = (LPBITMAPINFO) malloc(40 + 4*colors);//创建位图信息指针变量并分配内存

	memcpy(lpBitsInfo, &BHEADER, 40);//将位图信息头的数据复制到位图信息里

	//对位图信息进行颜色表的赋值
	if(colors == 256)
	{
		RGBQUAD* colorsTab = lpBitsInfo->bmiColors;
		for(i=0; i<256; i++)
		{	
			colorsTab[i].rgbBlue = colorsTab[i].rgbGreen = colorsTab[i].rgbRed = (BYTE)i;
			colorsTab[i].rgbReserved = 0;
		}	
	}

	//======颠倒数据
	//======Mat 中从上往下存，而bitmap中从下往上存。  都是从左往右，并且bitmap每一个点多占一个保留字节（针对真彩色图像，为了4字节对齐），
	//		默认255，灰度图像则不用这种对齐方法
	unsigned char *m_pDibBits;//存储图像中的数据，从下向上，从左向右
	//x行 * Y列
	int x,y; 
	unsigned char * bmpdata; // 负责行搬运
	unsigned char * imgData = img.data;
	if (bits == 8)
	{	
		m_pDibBits = new unsigned char[width1 * height];//注意此处用的是width1（对齐后的图像的像素宽度）而不是width

		//把imgData中的第一行复制到  m_pDibBits 的最后一行,依次颠倒
		for (x=0;  x<height;  x++ )
		{
			bmpdata = m_pDibBits + (height-1-x)*width1;//传输地址
			memcpy(bmpdata,imgData,width); // Mat中拷贝width个字节，不是width1
			imgData = imgData + width; // Mat中拷贝width个字节，不是width1，传输地址
		}
	} 
	else if (bits == 32)
	{
		m_pDibBits = new unsigned char[ width * height*4 ];

		//把imgData中的第一行复制到  m_pDibBits 的最后一行,依次颠倒
		for (x=0;  x<height;  x++ )
		{
			bmpdata = m_pDibBits + (height-1-x)*width*4;
			for (y = 0; y<width; y++)
			{
				memcpy(bmpdata,imgData,3);
				bmpdata[3] = 255;   // 注释掉 没有影响
				bmpdata = bmpdata+4;
				imgData = imgData+3;
			}    
		}
	}


	//显示图像部分
	SetStretchBltMode(pDC->GetSafeHdc(), COLORONCOLOR);
	int w = min(img.cols,ctrlRect.Width());
	int h = min(img.rows,ctrlRect.Height());

	StretchDIBits(pDC->GetSafeHdc(),
		0,
		0,
		w,
		h,
		0,
		0,
		width,
		height,
		m_pDibBits,
		lpBitsInfo,
		DIB_RGB_COLORS,
		SRCCOPY);

	//释放相关资源
	pimgShowCtrl->ReleaseDC(pDC);
	free(lpBitsInfo);
	delete []m_pDibBits;
}








void CjcshiliDlg::OnBnClicksaveImage()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
		CFileDialog dlg(false,_T(".dmp"),_T("*.dmp"),OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,_T("位图文件 (*.bmp)|*.bmp|JPEG文件 (*.jpg)|*.jpg|PNG文件 (*.png)|*.png||"));
	if(dlg.DoModal()==IDOK)  
	{  
		CString szFileName = dlg.GetPathName();//文件名
		CString ext = dlg.GetFileExt();//取得扩展名
		ext.MakeLower();//转为小写 
		CString str = szFileName+ext;
		string s(szFileName.GetBuffer());
		imwrite(s,outimage);
		str.ReleaseBuffer();
	}

	} 
}


void CjcshiliDlg::OnBnClickedFankuang()
{
	// TODO: 在此添加控件通知处理程序代码
	/*CRect Rect;
	(this->GetDlgItem(IDC_CHULITU))->GetClientRect(&Rect);
	GetDC()-> FillSolidRect(&Rect,RGB(240,240,240)); 
	g_dstImage1=m_srcImg.clone();*/
	//createTrackbar("内核值：","【<1>方框滤波】",&g_nFangKuanValue ,40,on_FangKuang);
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
		g_nFangKuanValue=m_int;
	boxFilter(m_srcImg,g_dstImage1,-1,Size(g_nFangKuanValue+1,g_nFangKuanValue+1));
	ShowImage(g_dstImage1, IDC_CHULITU);
	}
}





void CjcshiliDlg::OnBnClickedJunzhi()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
	 g_nJunZhiValue=m_int;
	 g_dstImage2=m_srcImg.clone();
	 blur(m_srcImg,g_dstImage2,Size(g_nJunZhiValue+1,g_nJunZhiValue+1),Point(-1,-1));
	 ShowImage(g_dstImage2, IDC_CHULITU);
	}

}


void CjcshiliDlg::OnBnClickedGaosi()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
		g_nGaoSiValue=m_int;
	g_dstImage3=m_srcImg.clone();
	GaussianBlur(m_srcImg,g_dstImage3,Size(g_nGaoSiValue*2+1,g_nGaoSiValue*2+1),0,0);
	ShowImage(g_dstImage3, IDC_CHULITU);
	}
}


void CjcshiliDlg::OnBnClickedZhongzhi()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
		g_nZhongZhiValue=m_int;
	g_dstImage4=m_srcImg.clone();
	medianBlur(m_srcImg,g_dstImage4,g_nZhongZhiValue*2+1);
	ShowImage(g_dstImage4, IDC_CHULITU);
	}

}


void CjcshiliDlg::OnBnClickedShuangbian()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
		g_nShuangZhiValue=m_int;
	g_dstImage5=m_srcImg.clone();
	bilateralFilter(m_srcImg,g_dstImage5,g_nShuangZhiValue,g_nShuangZhiValue*2,g_nShuangZhiValue/2);
	ShowImage(g_dstImage5, IDC_CHULITU);
	}
}


void CjcshiliDlg::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	*pResult = 0;
}


void CjcshiliDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if( pScrollBar->GetDlgCtrlID() == IDC_SLIDER3 ) 
	{ 
		// nPos就是此时滑杆的位置，显示到 CEdit 就可以了 
		char temp[30]; 
		sprintf_s(temp, 30, "%d", nPos); 

		//或者 获取 Slider 当前位置 
		sprintf_s(temp, 30, "%d", ((CSliderCtrl*)pScrollBar)->GetPos()); 

		GetDlgItem(IDC_EDIT1)->SetWindowText(temp); 
	} 
	CSliderCtrl   *pSlidCtrl=(CSliderCtrl*)GetDlgItem(IDC_SLIDER3);
	m_int=pSlidCtrl->GetPos();//取得当前位置值 
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CjcshiliDlg::OnBnClickedFushi()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nErodeNum=m_int;
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{int offset=g_nErodeNum-g_nMaxIterationNum;
	int Absolute_offset=offset > 0 ? offset : -offset;
	Mat element = getStructuringElement(g_nElementShape,Size(Absolute_offset*2+1,Absolute_offset*2+1),Point(Absolute_offset,Absolute_offset));
	erode(m_srcImg,g_dstImage6,element);
	ShowImage(g_dstImage6, IDC_CHULITU);
	}
}


void CjcshiliDlg::OnBnClickedPengzhang()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nDilateNum=m_int;
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
	int offset=g_nDilateNum-g_nMaxIterationNum;
	int Absolute_offset=offset > 0 ? offset : -offset;
	Mat element = getStructuringElement(g_nElementShape,Size(Absolute_offset*2+1,Absolute_offset*2+1),Point(Absolute_offset,Absolute_offset));
	dilate(m_srcImg,g_dstImage7,element);
	ShowImage(g_dstImage7, IDC_CHULITU);
	}
}


void CjcshiliDlg::OnBnClickedKaiyunsuan()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nOpenNum=m_int;
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
	int offset=g_nOpenNum-g_nMaxIterationNum;
	int Absolute_offset=offset> 0 ? offset : -offset;
	Mat element=getStructuringElement(g_nElementShape,Size(Absolute_offset*2+1,Absolute_offset*2+1),Point(Absolute_offset,Absolute_offset));
	morphologyEx(m_srcImg,g_dstImage8,CV_MOP_OPEN,element);
	ShowImage(g_dstImage8, IDC_CHULITU);
	}
}


void CjcshiliDlg::OnBnClickedBiyunsuan()
{
	// TODO: 在此添加控件通知处理程序代码
    g_nCloseNum=m_int;
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
	int offset=g_nCloseNum-g_nMaxIterationNum;
	int Absolute_offset=offset> 0 ? offset : -offset;
	Mat element=getStructuringElement(g_nElementShape,Size(Absolute_offset*2+1,Absolute_offset*2+1),Point(Absolute_offset,Absolute_offset));
	morphologyEx(m_srcImg,g_dstImage9,MORPH_CLOSE,element);
	ShowImage(g_dstImage9, IDC_CHULITU);
	}

}


void CjcshiliDlg::OnBnClickedDingmao()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nTopHatNum=m_int;
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
	int offset=g_nTopHatNum-g_nMaxIterationNum;
	int Absolute_offset =offset > 0 ? offset : -offset;
	Mat element=getStructuringElement(g_nElementShape,Size(Absolute_offset*2+1,Absolute_offset*2+1),Point(Absolute_offset,Absolute_offset));
	morphologyEx(m_srcImg,g_dstImage10,MORPH_TOPHAT,element);
	ShowImage(g_dstImage10, IDC_CHULITU);
	}

}



void CjcshiliDlg::OnBnClickedHeimao()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nBlackHatNum=m_int;
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
	int offset=g_nBlackHatNum-g_nMaxIterationNum;
	int Absolute_offset =offset > 0 ? offset : -offset;
	Mat element=getStructuringElement(g_nElementShape,Size(Absolute_offset*2+1,Absolute_offset*2+1),Point(Absolute_offset,Absolute_offset));
	morphologyEx(m_srcImg,g_dstImage11,MORPH_BLACKHAT,element);
	ShowImage(g_dstImage11, IDC_CHULITU);
	}
}


void CjcshiliDlg::OnBnClickedJiance()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	if(GetDlgItemText(IDC_JIANCE,str),str=="检测<<")
	{
		SetDlgItemText(IDC_JIANCE,"检测>>");
	}
	else
	{
		SetDlgItemText(IDC_JIANCE,"检测<<");
	}

	static CRect rectLarge;
	static CRect rectSmall;

	if(rectLarge.IsRectNull())
	{
		CRect rectSeparator;
		GetWindowRect(&rectLarge);
		GetDlgItem(IDC_SEPARATOR)->GetWindowRect(&rectSeparator);

		rectSmall.left=rectLarge.left;
		rectSmall.top=rectLarge.top;
		rectSmall.right=rectLarge.right;
		rectSmall.bottom=rectSeparator.bottom;
	}
	if(str=="检测<<")
	{
		SetWindowPos(NULL,0,0,rectSmall.Width(),rectSmall.Height(),
			SWP_NOMOVE | SWP_NOZORDER);
	}
	else
	{
		SetWindowPos(NULL,0,0,rectLarge.Width(),rectLarge.Height(),
			SWP_NOMOVE | SWP_NOZORDER);
	}

}


void CjcshiliDlg::OnBnClickedCannyjiance()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
	cvtColor(m_srcImg,g_srcGrayImage,COLOR_RGB2GRAY);
	blur(g_srcGrayImage,g_cannyDetectedEdges,Size(3,3));
	Canny(g_cannyDetectedEdges,g_cannyDetectedEdges,g_cannyLowThreshold,g_cannyLowThreshold*3,3);
	g_dstImage12=Scalar::all(0);
	m_srcImg.copyTo(g_dstImage12,g_cannyDetectedEdges);
	ShowImage(g_dstImage12, IDC_CHULITU);
	}


}


void CjcshiliDlg::OnBnClickedSobeljiance()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
	system("color 2F");
	g_dstImage13.create(m_srcImg.size(),m_srcImg.type());
	cvtColor(m_srcImg,g_srcGrayImage,COLOR_RGB2GRAY);
	Sobel(m_srcImg,g_sobelGradient_x,CV_16S,1,0,(2*g_sobelKernelSize+1),1,1,BORDER_DEFAULT);
	convertScaleAbs(g_sobelGradient_x,g_sobelAbsGradient_x);
	Sobel(m_srcImg,g_sobelGradient_y,CV_16S,0,1,(2*g_sobelKernelSize+1),1,1,BORDER_DEFAULT);
	convertScaleAbs(g_sobelGradient_y,g_sobelAbsGradient_y);
	addWeighted(g_sobelAbsGradient_x,0.5,g_sobelAbsGradient_y,0.5,0,g_dstImage13);
	ShowImage(g_dstImage13, IDC_CHULITU);
	}
}


void CjcshiliDlg::OnBnClickedScharrjiance()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
		g_dstImage14.create(m_srcImg.size(),m_srcImg.type());
	    Scharr(m_srcImg,g_scharrGradient_x,CV_16S,1,0,1,0,BORDER_DEFAULT);
	    convertScaleAbs(g_scharrGradient_x,g_scharrAbsGradient_x);
	    Scharr(m_srcImg,g_scharrGradient_y,CV_16S,0,1,1,0,BORDER_DEFAULT);
	    convertScaleAbs(g_scharrGradient_y,g_scharrAbsGradient_y);
	    addWeighted(g_scharrAbsGradient_x,0.5,g_scharrAbsGradient_y,0.5,0,g_dstImage14);
	    ShowImage(g_dstImage14, IDC_CHULITU);
	}
}


//HBRUSH CjcshiliDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
//{
//	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
//
//	// TODO:  在此更改 DC 的任何特性
//	if(pWnd->GetDlgCtrlID()==IDD_JCSHILI_DIALOG)
//	{
//		pDC->SetTextColor(RGB(122,122,0));
//		pDC->SetBkMode(RGB(125,121,121));
//		return m_brush;
//	}
//	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
//	return hbr;
//	
//}


void CjcshiliDlg::OnBnClickedFistchong()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
	g_dstImage15.create(m_srcImg.size(),m_srcImg.type());
	g_map_x.create(m_srcImg.size(),CV_32FC1);
	g_map_y.create(m_srcImg.size(),CV_32FC1);
	for(int j=0;j<m_srcImg.rows;j++)
	{
		for(int i=0;i<m_srcImg.cols;i++)
		{
			if(i>m_srcImg.cols*0.25 && i<m_srcImg.cols*0.75 && j > m_srcImg.rows*0.25 &&
				j < m_srcImg.rows*0.75)
			{
				g_map_x.at<float>(j,i)=static_cast<float>(2*(i-m_srcImg.cols*0.25)+0.5);
				g_map_y.at<float>(j,i)=static_cast<float>(2*(j-m_srcImg.rows*0.25)+0.5);

			}
			else
			{
				g_map_x.at<float>(j,i)=0;
				g_map_y.at<float>(j,i)=0;
			}
		}
	}
		remap(m_srcImg,g_dstImage15,g_map_x,g_map_y,INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));
		ShowImage(g_dstImage15, IDC_CHULITU);
	}
			
}


void CjcshiliDlg::OnBnClickedTwochong()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
		g_dstImage16.create(m_srcImg.size(),m_srcImg.type());
		g_map_x.create(m_srcImg.size(),CV_32FC1);
		g_map_y.create(m_srcImg.size(),CV_32FC1);
		for(int j=0;j<m_srcImg.rows;j++)
		{
			for(int i=0;i<m_srcImg.cols;i++)
			{
			g_map_x.at<float>(j,i)=static_cast<float>(i);
			g_map_y.at<float>(j,i)=static_cast<float>(m_srcImg.rows-j);
			}
		}
		remap(m_srcImg,g_dstImage16,g_map_x,g_map_y,INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));
		ShowImage(g_dstImage16, IDC_CHULITU);
	}
}


void CjcshiliDlg::OnBnClickedTreechong()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
		g_dstImage17.create(m_srcImg.size(),m_srcImg.type());
		g_map_x.create(m_srcImg.size(),CV_32FC1);
		g_map_y.create(m_srcImg.size(),CV_32FC1);
		for(int j=0;j<m_srcImg.rows;j++)
		{
			for(int i=0;i<m_srcImg.cols;i++)
			{
				g_map_x.at<float>(j,i)=static_cast<float>(m_srcImg.cols-i);
			    g_map_y.at<float>(j,i)=static_cast<float>(j);
			}
		}
		remap(m_srcImg,g_dstImage17,g_map_x,g_map_y,INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));
		ShowImage(g_dstImage17, IDC_CHULITU);
	}

}


void CjcshiliDlg::OnBnClickedFourchong()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!m_srcImg.data)
	{
		MessageBox("未打开图片~！ \n");
	}
	else
	{
		g_dstImage18.create(m_srcImg.size(),m_srcImg.type());
		g_map_x.create(m_srcImg.size(),CV_32FC1);
		g_map_y.create(m_srcImg.size(),CV_32FC1);
		for(int j=0;j<m_srcImg.rows;j++)
		{
			for(int i=0;i<m_srcImg.cols;i++)
			{
				g_map_x.at<float>(j,i)=static_cast<float>(m_srcImg.cols-i);
				g_map_y.at<float>(j,i)=static_cast<float>(m_srcImg.rows-j);
			}
		}
		remap(m_srcImg,g_dstImage18,g_map_x,g_map_y,INTER_LINEAR,BORDER_CONSTANT,Scalar(0,0,0));
		ShowImage(g_dstImage18, IDC_CHULITU);
	}


}


void CjcshiliDlg::OnBnClickedLightbuchang()
{
	g_nBrightValue=m_int;
	Mat g_dstImage22 = Mat::zeros(m_srcImg.size(),m_srcImg.type());
	for(int y=0;y<m_srcImg.rows;y++)
		for(int x=0;x<m_srcImg.cols;x++)
			for(int c=0 ;c<3 ;c++)
			{
				g_dstImage22.at<Vec3b>(y,x)[c]=saturate_cast<uchar>((m_srcImg.at<Vec3b>(y,x)[c])+g_nBrightValue);
			}
			ShowImage(g_dstImage22,IDC_CHULITU);
}


void CjcshiliDlg::OnBnClickedHuiduhua()
{
	// TODO: 在此添加控件通知处理程序代码
	cvtColor(m_srcImg,g_dstImage19,COLOR_BGR2GRAY);
	ShowImage(g_dstImage19,IDC_CHULITU);
}


void CjcshiliDlg::OnBnClickedErzhihua()
{
	// TODO: 在此添加控件通知处理程序代码
	Mat g_dstImage20;
	cvtColor(m_srcImg,m_srcImg,COLOR_BGR2GRAY);
	threshold(m_srcImg,g_dstImage20, 100, 255, CV_THRESH_BINARY);
	ShowImage(g_dstImage20,IDC_CHULITU);
}


void CjcshiliDlg::OnBnClickedZhifangtu()
{
	// TODO: 在此添加控件通知处理程序代码
	Mat g_dstImage21;
	cvtColor(m_srcImg,m_srcImg,COLOR_BGR2GRAY);
	equalizeHist(m_srcImg,g_dstImage21);
	ShowImage(g_dstImage21,IDC_CHULITU);
  
}


void CjcshiliDlg::OnBnClickedQuchugulidian()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nContrastValue=m_int;
	Mat g_dstImage22 = Mat::zeros(m_srcImg.size(),m_srcImg.type());
	for(int y=0;y<m_srcImg.rows;y++)
		for(int x=0;x<m_srcImg.cols;x++)
			for(int c=0 ;c<3 ;c++)
			{
				g_dstImage22.at<Vec3b>(y,x)[c]=saturate_cast<uchar>((m_srcImg.at<Vec3b>(y,x)[c])*g_nContrastValue*0.01);
			}
			ShowImage(g_dstImage22,IDC_CHULITU);
}

#pragma once

// VTK header files
#include <vtkPNGReader.h>
#include <vtkSmartPointer.h>
#include <vtkImageViewer2.h>
#include <vtkActor.h>
#include <vtkImageMapToWindowLevelColors.h>
#include <vtkImageData.h>
#include <vtkDICOMImageReader.h>
#include <vtkMetaImageReader.h>
#include <vtkImageResample.h>
#include <vtkVolume.h>
#include <vtkVolumeProperty.h>
#include <vtkFixedPointVolumeRayCastMapper.h> 
#include <vtkSmartVolumeMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkPiecewiseFunction.h>
#include <vtkColorTransferFunction.h>
#include <vtkExtractVOI.h>
#include <vtkImageActor.h>
#include <vtkPNGWriter.h>

// ITK header files
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>
#include <itkScalarImageKmeansImageFilter.h>
#include <itkConfidenceConnectedImageFilter.h>
#include <itkCurvatureFlowImageFilter.h>
#include <itkCastImageFilter.h>

// Qt header files
#include <QFileDialog.h>
#include <QMainWindow.h>
#include <QLayout.h>
#include <QPushButton.h>
#include <QVTKWidget.h>
#include <QSlider.h>
#include <QLabel.h>
#include <QString.h>
#include <QVTKWidget.h>
#include <QComboBox.h>
class ui : public QMainWindow
{
	Q_OBJECT
public:
	QWidget *widget;
	QVTKWidget *viewport1;
	QVTKWidget *viewport2;
	QVTKWidget *viewport3;
	QVTKWidget *viewport4;
	QVTKWidget *viewport5;
	QVTKWidget *viewport6;
	QVTKWidget *viewport7;
	QVTKWidget *viewport8;
	QPushButton *button1;
	QPushButton *button2;
	vtkSmartPointer<vtkImageViewer2> viewer2;
	vtkSmartPointer<vtkImageViewer2> viewer3;
	vtkSmartPointer<vtkImageViewer2> viewer4;
	vtkSmartPointer<vtkImageViewer2> viewer6;
	vtkSmartPointer<vtkImageViewer2> viewer7;
	vtkSmartPointer<vtkImageViewer2> viewer8;
	QSlider *slider1;
	QSlider *slider2;
	QLabel *label1;
	QLabel *label2;
	QLabel *label3;
	QLabel *label4;
	QLabel *label5;
	QLabel *label6;
	QLabel *label7;
	QLabel *label8;
	QLabel *label9;
	QLabel *label10;
	QLabel *labeln1;
	QLabel *labeln2;
	QLabel *seg1;
	char *filename_final;
	char *filename_final1;
	QComboBox *comboBox;
	QComboBox *comboBox1;
	double m;
	unsigned int i;
	ui()
	{
		// Resize the window
		this->resize(1500, 800);

		// Create the "central" (primary) widget for the window
		widget = new QWidget();
		this->setCentralWidget(widget);

		// Create your widgets
		viewport1 = new QVTKWidget();
		viewport2 = new QVTKWidget();
		viewport3 = new QVTKWidget();
		viewport4 = new QVTKWidget();
		viewport5 = new QVTKWidget();
		viewport6 = new QVTKWidget();
		viewport7 = new QVTKWidget();
		viewport8 = new QVTKWidget();
		viewport1->GetRenderWindow();
		viewport2->GetRenderWindow();
		viewport3->GetRenderWindow();
		viewport4->GetRenderWindow();
		viewport5->GetRenderWindow();
		viewport6->GetRenderWindow();
		viewport7->GetRenderWindow();
		viewport8->GetRenderWindow();
		button1 = new QPushButton("LOAD");
		button2 = new QPushButton("SEGMENT");
		slider1 = new QSlider(Qt::Horizontal, this);
		slider2 = new QSlider(Qt::Horizontal, this);
		label1 = new QLabel();
		label2 = new QLabel();
		label3 = new QLabel();
		label4 = new QLabel();
		label5 = new QLabel();
		label6 = new QLabel();
		label7 = new QLabel();
		label8 = new QLabel();
		label9 = new QLabel();
		label10 = new QLabel();
		labeln1 = new QLabel();
		labeln2 = new QLabel();
		seg1 = new QLabel();
		label1->setText("T1 Slice #");
		label2->setText("T2 Slice #");
		label3->setText("T1");
		label4->setText("T2");
		label5->setText("T1 Segmented - kmeans");
		label6->setText("T2 Segmented - kmeans");
		label7->setText("T1 Volume Rendered");
		label8->setText("T2 Volume Rendered");
		label9->setText("T1 Segmented - Confidence connected");
		label10->setText("T2 Segmented - Confidence connected");
		labeln1->setText(" ");
		labeln2->setText(" ");
		seg1->setText("Confidence Connected Segmentation Parameters");
		comboBox = new QComboBox();
		comboBox->addItem(tr("Multiplier = 1"));
		comboBox->addItem(tr("Multiplier = 2"));
		comboBox->addItem(tr("Multiplier = 3"));
		comboBox1 = new QComboBox();
		comboBox1->addItem(tr("Iterations = 1"));
		comboBox1->addItem(tr("Iterations = 10"));
		comboBox1->addItem(tr("Iterations = 25"));
		comboBox1->addItem(tr("Iterations = 50"));
		comboBox1->addItem(tr("Iterations = 100"));
		// Layout the widgets
		QHBoxLayout *layout_horizontal = new QHBoxLayout();
		widget->setLayout(layout_horizontal);

		QVBoxLayout *layout_vertical1 = new QVBoxLayout();
		layout_vertical1->addWidget(button1);
		QHBoxLayout *layout_horizontaln1 = new QHBoxLayout();
		layout_horizontaln1->addWidget(label1);
		layout_horizontaln1->addSpacing(1);
		layout_horizontaln1->addWidget(labeln1);
		layout_vertical1->addLayout(layout_horizontaln1);
		layout_vertical1->addWidget(slider1);
		QHBoxLayout *layout_horizontaln2 = new QHBoxLayout();
		layout_horizontaln2->addWidget(label2);
		layout_horizontaln2->addSpacing(1);
		layout_horizontaln2->addWidget(labeln2);
		layout_vertical1->addLayout(layout_horizontaln2);
		layout_vertical1->addWidget(slider2);
		layout_vertical1->addSpacing(300);
		layout_vertical1->addWidget(button2);
		layout_vertical1->addWidget(seg1);
		layout_vertical1->addWidget(comboBox);
		layout_vertical1->addWidget(comboBox1);
		layout_vertical1->addSpacing(200);
		layout_horizontal->addLayout(layout_vertical1);

		QVBoxLayout *layout_vertical2 = new QVBoxLayout();
		layout_vertical2->addWidget(label7);
		layout_vertical2->addWidget(viewport1);
		layout_vertical2->addWidget(label8);
		layout_vertical2->addWidget(viewport5);
		layout_horizontal->addLayout(layout_vertical2);
		QVBoxLayout *layout_vertical3 = new QVBoxLayout();
		layout_vertical3->addWidget(label3);
		layout_vertical3->addWidget(viewport2);
		layout_vertical3->addWidget(label4);
		layout_vertical3->addWidget(viewport6);
		layout_horizontal->addLayout(layout_vertical3);
		QVBoxLayout *layout_vertical4 = new QVBoxLayout();
		layout_vertical4->addWidget(label5);
		layout_vertical4->addWidget(viewport3);
		layout_vertical4->addWidget(label6);
		layout_vertical4->addWidget(viewport7);
		layout_horizontal->addLayout(layout_vertical4);
		QVBoxLayout *layout_vertical5 = new QVBoxLayout();
		layout_vertical5->addWidget(label9);
		layout_vertical5->addWidget(viewport4);
		layout_vertical5->addWidget(label10);
		layout_vertical5->addWidget(viewport8);
		layout_horizontal->addLayout(layout_vertical5);

		// Connected widget signals to slots
		connect(button1, SIGNAL(released()), this, SLOT(load_data()));
		connect(button2, SIGNAL(released()), this, SLOT(seg()));
		connect(slider1, SIGNAL(valueChanged(int)), this, SLOT(slider_changed1(int)));
		connect(slider2, SIGNAL(valueChanged(int)), this, SLOT(slider_changed2(int)));
		connect(comboBox, SIGNAL(activated(int)), this, SLOT(multiplier(int)));
		connect(comboBox1, SIGNAL(activated(int)), this, SLOT(niter(int)));
		// Display the window
		this->show();
	}

	public slots:
	void load_data()
	{
		// Opening T1 image 
		vtkSmartPointer<vtkMetaImageReader> reader = vtkSmartPointer<vtkMetaImageReader>::New();
		QString fileName = QFileDialog::getOpenFileName(this, tr("Please select T1 Meta Image"),
			"C:/engg199-03/data/", tr("Images (*.mha)"));
		std::string filename = fileName.toUtf8().constData();
		char *temp = new char[filename.size() + 1];
		strcpy(temp, filename.c_str());
		filename_final = temp;
		reader->SetFileName(filename_final);
		reader->Update();

		// Opening T2 image 
		vtkSmartPointer<vtkMetaImageReader> reader1 = vtkSmartPointer<vtkMetaImageReader>::New();
		QString fileName1 = QFileDialog::getOpenFileName(this, tr("Please select T2 Meta Image"),
			"C:/engg199-03/data/", tr("Images (*.mha)"));
		std::string filename1 = fileName1.toUtf8().constData();
		char *temp1 = new char[filename.size() + 1];
		strcpy(temp1, filename1.c_str());
		filename_final1 = temp1;
		reader1->SetFileName(filename_final1);
		reader1->Update();

		// Displaying T1 image
		vtkSmartPointer<vtkImageData> im = reader->GetOutput();
		viewer2 = vtkSmartPointer<vtkImageViewer2>::New();
		viewer2->SetInputConnection(reader->GetOutputPort());
		viewer2->SetRenderWindow(viewport2->GetRenderWindow());
		viewer2->Render();
		// Change slice #  
		slider1->setRange(viewer2->GetSliceMin(), viewer2->GetSliceMax());
		// Volume rendering of T1 image
		vtkSmartPointer<vtkRenderer> ren1 = vtkSmartPointer<vtkRenderer>::New();
		ren1->SetBackground(0, 0, 0);
		viewport1->GetRenderWindow()->AddRenderer(ren1);
		viewport1->GetRenderWindow()->Render();
		vtkSmartPointer<vtkSmartVolumeMapper> volumeMapper = vtkSmartPointer<vtkSmartVolumeMapper>::New();
		volumeMapper->SetBlendModeToComposite();
		volumeMapper->SetInputConnection(reader->GetOutputPort());
		vtkSmartPointer<vtkVolumeProperty> volumeProperty = vtkSmartPointer<vtkVolumeProperty>::New();
		volumeProperty->ShadeOff();
		volumeProperty->SetInterpolationType(VTK_LINEAR_INTERPOLATION);
		vtkSmartPointer<vtkPiecewiseFunction> compositeOpacity = vtkSmartPointer<vtkPiecewiseFunction>::New();
		compositeOpacity->AddPoint(0.0, 0.0);
		compositeOpacity->AddPoint(200.0, 0.02);
		compositeOpacity->AddPoint(201.0, 0.06);
		compositeOpacity->AddPoint(900.0, 0.12);
		volumeProperty->SetScalarOpacity(compositeOpacity); // composite first
		vtkSmartPointer<vtkColorTransferFunction> color = vtkSmartPointer<vtkColorTransferFunction>::New();
		color->AddRGBPoint(0.0, 0.0, 0.0, 1.0);
		color->AddRGBPoint(150.0, 0.2, 0.7, 1.0);
		color->AddRGBPoint(300.0, 1.0, 1.0, 1.0);
		color->AddRGBPoint(900.0, 1.0, 1.0, 1.0);
		volumeProperty->SetColor(color);
		vtkSmartPointer<vtkVolume> volume = vtkSmartPointer<vtkVolume>::New();
		volume->SetMapper(volumeMapper);
		volume->SetProperty(volumeProperty);
		ren1->AddViewProp(volume);
		ren1->ResetCamera();
		viewport1->GetRenderWindow()->Render();
		volumeMapper->SetRequestedRenderModeToRayCast();
		viewport1->GetRenderWindow()->Render();

		// Displaying T2 images
		vtkSmartPointer<vtkImageData> im1 = reader1->GetOutput();
		viewer6 = vtkSmartPointer<vtkImageViewer2>::New();
		viewer6->SetInputConnection(reader1->GetOutputPort());
		viewer6->SetRenderWindow(viewport6->GetRenderWindow());
		viewer6->Render();
		// Change slice #  
		slider2->setRange(viewer6->GetSliceMin(), viewer6->GetSliceMax());
		// Volume rendering of T2 image
		vtkSmartPointer<vtkRenderer> ren2 = vtkSmartPointer<vtkRenderer>::New();
		ren2->SetBackground(0, 0, 0);
		viewport5->GetRenderWindow()->AddRenderer(ren2);
		viewport5->GetRenderWindow()->Render();
		vtkSmartPointer<vtkSmartVolumeMapper> volumeMapper1 = vtkSmartPointer<vtkSmartVolumeMapper>::New();
		volumeMapper1->SetBlendModeToComposite();
		volumeMapper1->SetInputConnection(reader1->GetOutputPort());
		vtkSmartPointer<vtkVolumeProperty> volumeProperty1 = vtkSmartPointer<vtkVolumeProperty>::New();
		volumeProperty1->ShadeOff();
		volumeProperty1->SetInterpolationType(VTK_LINEAR_INTERPOLATION);
		vtkSmartPointer<vtkPiecewiseFunction> compositeOpacity1 = vtkSmartPointer<vtkPiecewiseFunction>::New();
		compositeOpacity1->AddPoint(0.0, 0.0);
		compositeOpacity1->AddPoint(200.0, 0.02);
		compositeOpacity1->AddPoint(201.0, 0.06);
		compositeOpacity1->AddPoint(900.0, 0.12);
		volumeProperty1->SetScalarOpacity(compositeOpacity1); // composite first
		vtkSmartPointer<vtkColorTransferFunction> color1 = vtkSmartPointer<vtkColorTransferFunction>::New();
		color1->AddRGBPoint(0.0, 0.0, 0.0, 1.0);
		color1->AddRGBPoint(150.0, 0.2, 0.7, 1.0);
		color1->AddRGBPoint(300.0, 1.0, 1.0, 1.0);
		color1->AddRGBPoint(900.0, 1.0, 1.0, 1.0);
		volumeProperty1->SetColor(color1);
		vtkSmartPointer<vtkVolume> volume1 = vtkSmartPointer<vtkVolume>::New();
		volume1->SetMapper(volumeMapper1);
		volume1->SetProperty(volumeProperty1);
		ren2->AddViewProp(volume1);
		ren2->ResetCamera();
		viewport5->GetRenderWindow()->Render();
		volumeMapper1->SetRequestedRenderModeToRayCast();
		viewport5->GetRenderWindow()->Render();

	}
	void seg()
	{
		// for T1
		//Save current image slice
		vtkSmartPointer<vtkPNGWriter> pngwriter = vtkSmartPointer<vtkPNGWriter>::New();
		pngwriter->SetFileName("C:/engg199-03/data/slice_to_segment.png");
		pngwriter->SetInputData(viewer2->GetImageActor()->GetInput());
		pngwriter->Write();
		//kmeans segmentation
		itk::ImageFileReader<itk::Image<unsigned char, 2>>::Pointer itkreader = itk::ImageFileReader<itk::Image<unsigned char, 2>>::New();
		itkreader->SetFileName("C:/engg199-03/data/slice_to_segment.png");
		itk::ScalarImageKmeansImageFilter<itk::Image<unsigned char, 2>>::Pointer kmeans = itk::ScalarImageKmeansImageFilter<itk::Image<unsigned char, 2>>::New();
		kmeans->SetInput(itkreader->GetOutput());
		kmeans->AddClassWithInitialMean(5);
		kmeans->AddClassWithInitialMean(150);
		kmeans->AddClassWithInitialMean(250);
		kmeans->Update();
		itk::ImageFileWriter<itk::Image<unsigned char, 2>>::Pointer writer = itk::ImageFileWriter<itk::Image<unsigned char, 2>>::New();
		writer->SetFileName("C:/engg199-03/data/segimage1-kmeans.png");
		writer->SetInput(kmeans->GetOutput());
		writer->Update();
		//view kmeans segmented image
		vtkSmartPointer<vtkPNGReader> reader = vtkSmartPointer<vtkPNGReader>::New();
		reader->SetFileName("C:/engg199-0/data/segimage1-kmeans.png");
		reader->Update();
		viewer3 = vtkSmartPointer<vtkImageViewer2>::New();
		viewer3->SetInputConnection(reader->GetOutputPort());
		viewer3->SetRenderWindow(viewport3->GetRenderWindow());
		viewer3->GetWindowLevel()->SetLevel(1);
		viewer3->GetWindowLevel()->SetWindow(2);
		viewer3->Render();
		// confidence connected segmentation
		m = 1;
		i = 1;
		itk::ImageFileReader<itk::Image< unsigned char, 2 >>::Pointer itkreader1 = itk::ImageFileReader<itk::Image< unsigned char, 2 >>::New();
		itkreader1->SetFileName("C:/engg199-03/data/slice_to_segment.png");
		itkreader1->Update();
		itk::ConfidenceConnectedImageFilter<itk::Image<unsigned char, 2>, itk::Image<unsigned char, 2>>::Pointer confidenceConnectedFilter = itk::ConfidenceConnectedImageFilter<itk::Image<unsigned char, 2>, itk::Image<unsigned char, 2>>::New();
		confidenceConnectedFilter->SetInitialNeighborhoodRadius(10);
		confidenceConnectedFilter->SetMultiplier(m);
		confidenceConnectedFilter->SetNumberOfIterations(i);
		confidenceConnectedFilter->SetReplaceValue(255);
		itk::Image< unsigned char, 2 >::IndexType seed;
		seed[0] = 300;
		seed[1] = 150;
		confidenceConnectedFilter->SetSeed(seed);
		confidenceConnectedFilter->SetInput(itkreader1->GetOutput());
		itk::ImageFileWriter<itk::Image<unsigned char, 2>>::Pointer writer1 = itk::ImageFileWriter<itk::Image<unsigned char, 2>>::New();
		writer1->SetFileName("C:/engg199-03/data/segimage1-cc.png");
		writer1->SetInput(confidenceConnectedFilter->GetOutput());
		writer1->Update();
		// view confidence connected segmentation
		vtkSmartPointer<vtkPNGReader> reader1 = vtkSmartPointer<vtkPNGReader>::New();
		reader1->SetFileName("C:/engg199-03/data/segimage1-cc.png");
		reader1->Update();
		viewer4 = vtkSmartPointer<vtkImageViewer2>::New();
		viewer4->SetInputConnection(reader1->GetOutputPort());
		viewer4->SetRenderWindow(viewport4->GetRenderWindow());
		viewer4->GetWindowLevel()->SetLevel(1);
		viewer4->GetWindowLevel()->SetWindow(2);
		viewer4->Render();


		// for T2
		//Save current image slice
		vtkSmartPointer<vtkPNGWriter> pngwriter1 = vtkSmartPointer<vtkPNGWriter>::New();
		pngwriter1->SetFileName("C:/engg199-03/data/slice_to_segment2.png");
		pngwriter1->SetInputData(viewer6->GetImageActor()->GetInput());
		pngwriter1->Write();
		//kmeans segmentation
		itk::ImageFileReader<itk::Image<unsigned char, 2>>::Pointer itkreadert2 = itk::ImageFileReader<itk::Image<unsigned char, 2>>::New();
		itkreadert2->SetFileName("C:/engg199-03/data/slice_to_segment2.png");
		itk::ScalarImageKmeansImageFilter<itk::Image<unsigned char, 2>>::Pointer kmeans1 = itk::ScalarImageKmeansImageFilter<itk::Image<unsigned char, 2>>::New();
		kmeans1->SetInput(itkreadert2->GetOutput());
		kmeans1->AddClassWithInitialMean(5);
		kmeans1->AddClassWithInitialMean(150);
		kmeans1->AddClassWithInitialMean(250);
		kmeans1->Update();
		itk::ImageFileWriter<itk::Image<unsigned char, 2>>::Pointer writert2 = itk::ImageFileWriter<itk::Image<unsigned char, 2>>::New();
		writert2->SetFileName("C:/engg199-03/data/segimage1-kmeans2.png");
		writert2->SetInput(kmeans1->GetOutput());
		writert2->Update();
		//view kmeans segmented image
		vtkSmartPointer<vtkPNGReader> readert2 = vtkSmartPointer<vtkPNGReader>::New();
		readert2->SetFileName("C:/engg199-03/data/segimage1-kmeans2.png");
		readert2->Update();
		viewer7 = vtkSmartPointer<vtkImageViewer2>::New();
		viewer7->SetInputConnection(readert2->GetOutputPort());
		viewer7->SetRenderWindow(viewport7->GetRenderWindow());
		viewer7->GetWindowLevel()->SetLevel(1);
		viewer7->GetWindowLevel()->SetWindow(2);
		viewer7->Render();
		// confidence connected segmentation
		m = 1;
		i = 1;
		itk::ImageFileReader<itk::Image< unsigned char, 2 >>::Pointer itkreader1t2 = itk::ImageFileReader<itk::Image< unsigned char, 2 >>::New();
		itkreader1t2->SetFileName("C:/engg199-03/data/slice_to_segment2.png");
		itkreader1t2->Update();
		itk::ConfidenceConnectedImageFilter<itk::Image<unsigned char, 2>, itk::Image<unsigned char, 2>>::Pointer confidenceConnectedFilter1 = itk::ConfidenceConnectedImageFilter<itk::Image<unsigned char, 2>, itk::Image<unsigned char, 2>>::New();
		confidenceConnectedFilter1->SetInitialNeighborhoodRadius(10);
		confidenceConnectedFilter1->SetMultiplier(m);
		confidenceConnectedFilter1->SetNumberOfIterations(i);
		confidenceConnectedFilter1->SetReplaceValue(255);
		itk::Image< unsigned char, 2 >::IndexType seed1;
		seed1[0] = 300;
		seed1[1] = 150;
		confidenceConnectedFilter1->SetSeed(seed1);
		confidenceConnectedFilter1->SetInput(itkreader1t2->GetOutput());
		itk::ImageFileWriter<itk::Image<unsigned char, 2>>::Pointer writer1t2 = itk::ImageFileWriter<itk::Image<unsigned char, 2>>::New();
		writer1t2->SetFileName("C:/engg199-03/data/segimage1-cc2.png");
		writer1t2->SetInput(confidenceConnectedFilter1->GetOutput());
		writer1t2->Update();
		// view confidence connected segmentation
		vtkSmartPointer<vtkPNGReader> reader1t2 = vtkSmartPointer<vtkPNGReader>::New();
		reader1t2->SetFileName("C:/engg199-03/data/segimage1-cc2.png");
		reader1t2->Update();
		viewer8 = vtkSmartPointer<vtkImageViewer2>::New();
		viewer8->SetInputConnection(reader1t2->GetOutputPort());
		viewer8->SetRenderWindow(viewport8->GetRenderWindow());
		viewer8->GetWindowLevel()->SetLevel(1);
		viewer8->GetWindowLevel()->SetWindow(2);
		viewer8->Render();

	}
	void slider_changed1(int value)
	{
		if (viewer2 != NULL)
		{
			viewer2->SetSlice(value);
			viewer2->Render();
			labeln1->setText(QString::number(value));
		}
	}
	void slider_changed2(int value)
	{
		if (viewer6 != NULL)
		{
			viewer6->SetSlice(value);
			viewer6->Render();
			labeln2->setText(QString::number(value));
		}
	}
	void multiplier(int value)
	{
		if (value == 1) { m = 1; }
		if (value == 2) { m = 1.8; }
		if (value == 3) { m = 3; }
	}

};
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
	char *filename_final;
	char *filename_final1;
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

		// Layout the widgets
		QHBoxLayout *layout_horizontal = new QHBoxLayout();
		widget->setLayout(layout_horizontal);

		QVBoxLayout *layout_vertical1 = new QVBoxLayout();
		layout_vertical1->addWidget(button1);
		QHBoxLayout *layout_horizontaln1 = new QHBoxLayout();
		layout_horizontaln1->addWidget(label1);
		layout_horizontaln1->addSpacing(5);
		layout_horizontaln1->addWidget(labeln1);
		layout_vertical1->addLayout(layout_horizontaln1);
		layout_vertical1->addWidget(slider1);
		QHBoxLayout *layout_horizontaln2 = new QHBoxLayout();
		layout_horizontaln2->addWidget(label2);
		layout_horizontaln2->addSpacing(5);
		layout_horizontaln2->addWidget(labeln2);
		layout_vertical1->addLayout(layout_horizontaln2);
		layout_vertical1->addWidget(slider2);
		layout_vertical1->addSpacing(300);
		layout_vertical1->addWidget(button2);
		layout_vertical1->addSpacing(300);
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

		/*vtkSmartPointer<vtkExtractVOI> extractVOI = vtkSmartPointer<vtkExtractVOI>::New();
		extractVOI->SetInputConnection(reader->GetOutputPort());
		extractVOI->SetVOI(0, reader->GetWidth()+1, 0, reader->GetHeight()+1, 0, 0);
		extractVOI->Update();
		vtkImageData* extracted = extractVOI->GetOutput();
		ren1->AddViewProp(volume);
		ren1->ResetCamera();
		viewport1->GetRenderWindow()->Render();
		volumeMapper->SetRequestedRenderModeToRayCast();
		viewport1->GetRenderWindow()->Render();*/
	}
	void seg()
	{
		// save current image slice
		vtkSmartPointer<vtkPNGWriter> pngwriter = vtkSmartPointer<vtkPNGWriter>::New();
		pngwriter->SetFileName("C:/engg199-03/data/slice_to_segment.png");
		pngwriter->SetInputData(viewer2->GetImageActor()->GetInput());
		pngwriter->Write();

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

		vtkSmartPointer<vtkPNGReader> reader = vtkSmartPointer<vtkPNGReader>::New();
		reader->SetFileName("C:/engg199-03/data/segimage1-kmeans.png");
		reader->Update();
		viewer3 = vtkSmartPointer<vtkImageViewer2>::New();
		viewer3->SetInputConnection(reader->GetOutputPort());
		viewer3->SetRenderWindow(viewport3->GetRenderWindow());
		viewer3->GetWindowLevel()->SetLevel(1);
		viewer3->GetWindowLevel()->SetWindow(2);
		viewer3->Render();
		//slider1->setRange(viewer3->GetSliceMin(), viewer3->GetSliceMax());

		itk::ImageFileReader<itk::Image< unsigned char, 2 >>::Pointer itkreader1 = itk::ImageFileReader<itk::Image< unsigned char, 2 >>::New();
		itkreader1->SetFileName("C:/engg199-03/data/slice_to_segment.png");
		itkreader1->Update();
		itk::ConfidenceConnectedImageFilter<itk::Image<unsigned char, 2>, itk::Image<unsigned char, 2>>::Pointer confidenceConnectedFilter = itk::ConfidenceConnectedImageFilter<itk::Image<unsigned char, 2>, itk::Image<unsigned char, 2>>::New();
		confidenceConnectedFilter->SetInitialNeighborhoodRadius(10);
		confidenceConnectedFilter->SetMultiplier(1.8);
		confidenceConnectedFilter->SetNumberOfIterations(32);
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

		vtkSmartPointer<vtkPNGReader> reader1 = vtkSmartPointer<vtkPNGReader>::New();
		reader1->SetFileName("C:/engg199-03/data/segimage1-cc.png");
		reader1->Update();
		viewer4 = vtkSmartPointer<vtkImageViewer2>::New();
		viewer4->SetInputConnection(reader1->GetOutputPort());
		viewer4->SetRenderWindow(viewport4->GetRenderWindow());
		viewer4->GetWindowLevel()->SetLevel(1);
		viewer4->GetWindowLevel()->SetWindow(2);
		viewer4->Render();

	}
	void slider_changed1(int value)
	{
		if (viewer2 != NULL)
		{
			viewer2->SetSlice(value);
			viewer2->Render();
			labeln1->setText(QString::number(value));
		}
		if (viewer3 != NULL)
		{
			viewer3->SetSlice(value);
			viewer3->Render();
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
		if (viewer7 != NULL)
		{
			viewer7->SetSlice(value);
			viewer7->Render();
			labeln2->setText(QString::number(value));
		}
	}

};
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

// ITK header files
#include <itkImage.h>
#include <itkImageFileReader.h>
#include <itkImageFileWriter.h>
#include <itkScalarImageKmeansImageFilter.h>

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
	QPushButton *button1;
	QPushButton *button2;
	vtkSmartPointer<vtkImageViewer2> viewer1;
	vtkSmartPointer<vtkImageViewer2> viewer2;
	vtkSmartPointer<vtkImageViewer2> viewer3; 
	vtkSmartPointer<vtkImageViewer2> viewer4;
	vtkSmartPointer<vtkImageViewer2> viewer5;
	QSlider *slider1;
	QSlider *slider2;
	char *filename_final;
	char *filename_final1;
	ui()
	{
		// Resize the window
		this->resize(1200,800);

		// Create the "central" (primary) widget for the window
		widget = new QWidget();
		this->setCentralWidget(widget);

		// Create your widgets
		viewport1 = new QVTKWidget();
		viewport2 = new QVTKWidget();
		viewport3 = new QVTKWidget();
		viewport4 = new QVTKWidget();
		viewport5 = new QVTKWidget();
		viewport1->GetRenderWindow();
		viewport2->GetRenderWindow();
		viewport3->GetRenderWindow();
		viewport4->GetRenderWindow();
		viewport5->GetRenderWindow();
		button1 = new QPushButton("Load");
		button2 = new QPushButton("Segment");
		slider1 = new QSlider(Qt::Horizontal, this);
		slider2 = new QSlider(Qt::Horizontal, this);
		
		// Layout the widgets
		QHBoxLayout *layout_horizontal = new QHBoxLayout();
		widget->setLayout(layout_horizontal);
		QVBoxLayout *layout_vertical1 = new QVBoxLayout();
		layout_vertical1->addWidget(button1);
		layout_vertical1->addWidget(slider1);
		layout_vertical1->addWidget(slider2);
		layout_vertical1->addSpacing(100);
		layout_vertical1->addWidget(button2);
		layout_horizontal->addLayout(layout_vertical1);
		QVBoxLayout *layout_vertical2 = new QVBoxLayout();
		layout_vertical2->addSpacing(200);
		layout_vertical2->addWidget(viewport1);
		layout_vertical2->addSpacing(200);
		layout_horizontal->addLayout(layout_vertical2);
		QVBoxLayout *layout_vertical3 = new QVBoxLayout();
		layout_vertical3->addWidget(viewport2);
		layout_vertical3->addWidget(viewport3);
		layout_horizontal->addLayout(layout_vertical3);
		QVBoxLayout *layout_vertical4 = new QVBoxLayout();
		layout_vertical4->addWidget(viewport4);
		layout_vertical4->addWidget(viewport5);
		layout_horizontal->addLayout(layout_vertical4);

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
	vtkSmartPointer<vtkMetaImageReader> reader = vtkSmartPointer<vtkMetaImageReader>::New();
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Meta Image"),"C:/Users/F003584/engg199-03/project/data/",tr("Images (*.mha)"));
	std::string filename = fileName.toUtf8().constData();
	char *temp = new char[filename.size() + 1];
	strcpy(temp, filename.c_str());
	filename_final = temp;
	reader->SetFileName(filename_final);
	reader->Update();
	vtkSmartPointer<vtkImageData> im = reader->GetOutput();
	viewer2 = vtkSmartPointer<vtkImageViewer2>::New();
	viewer2->SetInputConnection(reader->GetOutputPort());
	viewer2->SetRenderWindow(viewport2->GetRenderWindow());
	viewer2->Render();
	slider1->setRange(viewer2->GetSliceMin(), viewer2->GetSliceMax());

	vtkSmartPointer<vtkMetaImageReader> reader1 = vtkSmartPointer<vtkMetaImageReader>::New();
	QString fileName1 = QFileDialog::getOpenFileName(this, tr("Open Meta Image"), "C:/Users/F003584/engg199-03/project/data/", tr("Images (*.mha)"));
	std::string filename1 = fileName1.toUtf8().constData();
	char *temp1 = new char[filename1.size() + 1];
	strcpy(temp1, filename1.c_str());
	filename_final1 = temp1;
	reader1->SetFileName(filename_final1);
	reader1->Update();
	vtkSmartPointer<vtkImageData> im1 = reader1->GetOutput();
	viewer4 = vtkSmartPointer<vtkImageViewer2>::New();
	viewer4->SetInputConnection(reader1->GetOutputPort());
	viewer4->SetRenderWindow(viewport4->GetRenderWindow());
	viewer4->Render();
	slider2->setRange(viewer4->GetSliceMin(), viewer4->GetSliceMax());
}
void seg()
{
	itk::ImageFileReader<itk::Image<unsigned char, 2>>::Pointer itkreader = itk::ImageFileReader<itk::Image<unsigned char, 2>>::New();
	itkreader->SetFileName(filename_final);
	itk::ScalarImageKmeansImageFilter<itk::Image<unsigned char, 2>>::Pointer kmeans = itk::ScalarImageKmeansImageFilter<itk::Image<unsigned char, 2>>::New();
	kmeans->SetInput(itkreader->GetOutput());
	kmeans->AddClassWithInitialMean(5);
	kmeans->AddClassWithInitialMean(100);
	kmeans->AddClassWithInitialMean(200);
	kmeans->Update();
	itk::ImageFileWriter<itk::Image<unsigned char, 2>>::Pointer writer = itk::ImageFileWriter<itk::Image<unsigned char, 2>>::New();
	writer->SetFileName("C:/Users/F003584/engg199-03/project/data/segimage1.mha");
	writer->SetInput(kmeans->GetOutput());
	writer->Update();

	vtkSmartPointer<vtkMetaImageReader> reader = vtkSmartPointer<vtkMetaImageReader>::New();
	reader->SetFileName("C:/Users/F003584/engg199-03/project/data/segimage1.mha");
	reader->Update();
	viewer3 = vtkSmartPointer<vtkImageViewer2>::New();
	viewer3->SetInputConnection(reader->GetOutputPort());
	viewer3->SetRenderWindow(viewport3->GetRenderWindow());
	viewer3->GetWindowLevel()->SetLevel(1);
	viewer3->GetWindowLevel()->SetWindow(2);
	viewer3->Render();

	itk::ImageFileReader<itk::Image<unsigned char, 2>>::Pointer itkreader1 = itk::ImageFileReader<itk::Image<unsigned char, 2>>::New();
	itkreader1->SetFileName(filename_final1);
	itk::ScalarImageKmeansImageFilter<itk::Image<unsigned char, 2>>::Pointer kmeans1 = itk::ScalarImageKmeansImageFilter<itk::Image<unsigned char, 2>>::New();
	kmeans1->SetInput(itkreader1->GetOutput());
	kmeans1->AddClassWithInitialMean(5);
	kmeans1->AddClassWithInitialMean(100);
	kmeans1->AddClassWithInitialMean(200);
	kmeans1->Update();
	itk::ImageFileWriter<itk::Image<unsigned char, 2>>::Pointer writer1 = itk::ImageFileWriter<itk::Image<unsigned char, 2>>::New();
	writer1->SetFileName("C:/Users/F003584/engg199-03/project/data/segimage2.mha");
	writer1->SetInput(kmeans1->GetOutput());
	writer1->Update();

	vtkSmartPointer<vtkMetaImageReader> reader1 = vtkSmartPointer<vtkMetaImageReader>::New();
	reader1->SetFileName("C:/Users/F003584/engg199-03/project/data/segimage2.mha");
	reader1->Update();
	viewer5 = vtkSmartPointer<vtkImageViewer2>::New();
	viewer5->SetInputConnection(reader1->GetOutputPort());
	viewer5->SetRenderWindow(viewport5->GetRenderWindow());
	viewer5->GetWindowLevel()->SetLevel(1);
	viewer5->GetWindowLevel()->SetWindow(2);
	viewer5->Render();
}
void slider_changed1(int value)
{
	if (viewer2 != NULL)
	{
		viewer2->SetSlice(value);
		viewer2->Render();
	}
	if (viewer3 != NULL)
	{
		viewer3->SetSlice(value);
		viewer3->Render();
	}
}
void slider_changed2(int value)
{
	if (viewer4 != NULL)
	{
		viewer4->SetSlice(value);
		viewer4->Render();
	}
	if (viewer5 != NULL)
	{
		viewer5->SetSlice(value);
		viewer5->Render();
	}
}

};
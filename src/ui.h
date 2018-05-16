
// Prevent this header file from being included multiple times
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


// Class that represents the main window for our application
class ui : public QMainWindow
{
	Q_OBJECT
public:
	// CLASS VARIABLES HERE
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
	// Constructor (happens when created)
	ui()
	{
		// Resize the window
		this->resize(1200,800); // CHANGE THIS

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
		layout_vertical1->addSpacing(100);
		layout_vertical1->addWidget(button2);
		layout_vertical1->addWidget(slider2);
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

public slots: // This tells Qt we are defining slots here
void load_data()
{
	vtkSmartPointer<vtkMetaImageReader> reader = vtkSmartPointer<vtkMetaImageReader>::New();
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Meta Image"),"C:/",tr("Images (*.mha)"));
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

	/*vtkSmartPointer<vtkMetaImageReader> reader1 = vtkSmartPointer<vtkMetaImageReader>::New();
	QString fileName1 = QFileDialog::getOpenFileName(this, tr("Open Meta Image"), "C:/", tr("Images (*.mha)"));
	std::string filename1 = fileName.toUtf8().constData();
	char *temp1 = new char[filename1.size() + 1];
	strcpy(temp1, filename1.c_str());
	filename_final = temp1;
	reader1->SetFileName(filename_final);
	reader1->Update();
	viewer4 = vtkSmartPointer<vtkImageViewer2>::New();
	viewer4->SetInputConnection(reader->GetOutputPort());
	viewer4->SetRenderWindow(viewport4->GetRenderWindow());
	viewer4->Render();*/
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
	writer->SetFileName("C:/engg199-03/project/data/segmented image.png");
	writer->SetInput(kmeans->GetOutput());
	writer->Update();

	vtkSmartPointer<vtkPNGReader> reader = vtkSmartPointer<vtkPNGReader>::New();
	reader->SetFileName("C:/engg199-03/project/data/segmented image.png");
	reader->Update();
	viewer2 = vtkSmartPointer<vtkImageViewer2>::New();
	viewer2->SetInputConnection(reader->GetOutputPort());
	viewer2->SetRenderWindow(viewport2->GetRenderWindow());
	viewer2->GetWindowLevel()->SetLevel(1);
	viewer2->GetWindowLevel()->SetWindow(2);
	slider1->setRange(0,10);
	viewer2->Render();
}
void slider_changed1(int value)
{
	if (viewer2 != NULL)
	{
		viewer2->SetSlice(value);
		viewer2->Render();
	}
}
void slider_changed2(int value)
{
	if (viewer2 != NULL)
	{
		viewer2->GetWindowLevel()->SetWindow(value);
		viewer2->Render();
	}
}
};
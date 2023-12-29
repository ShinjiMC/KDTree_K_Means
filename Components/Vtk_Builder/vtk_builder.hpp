#ifndef VTK_BUILDER_HPP
#define VTK_BUILDER_HPP

#include <vtkActor.h>
#include <vtkCamera.h>
#include <vtkCellArray.h>
#include <vtkFloatArray.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyData.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkProperty.h>
#include <vtkVertexGlyphFilter.h>
#include <vtkOrientationMarkerWidget.h>
#include <vtkAxesActor.h>
#include <vtkStdString.h>
#include <vtkAppendPolyData.h>
#include <vtkLineSource.h>
#include "../Vec2D/vec2d.hpp"

class Vtk_Builder
{

public:
    Vtk_Builder();
    ~Vtk_Builder() = default;
    void addClusters(std::vector<std::vector<Vec2D>> clusters);
    void show();
    void clear();

private:
    vtkSmartPointer<vtkRenderer> renderer;
    vtkSmartPointer<vtkRenderWindow> renderWindow;
    vtkSmartPointer<vtkRenderWindowInteractor> renderWindowInteractor;
    vtkSmartPointer<vtkAxesActor> axes;
    vtkSmartPointer<vtkNamedColors> colors;
    vtkSmartPointer<vtkOrientationMarkerWidget> widget;
    vtkSmartPointer<vtkPoints> points;
    vtkSmartPointer<vtkAppendPolyData> linesBlue;
    vtkSmartPointer<vtkAppendPolyData> linesGreen;
    vtkSmartPointer<vtkAppendPolyData> linesRed;

    vtkSmartPointer<vtkPoints> cluster1, cluster2, cluster3, cluster4, cluster5, cluster6,
        cluster7, cluster8, cluster9, cluster10, cluster11, cluster12, cluster13, cluster14,
        cluster15, cluster16, cluster17, cluster18;
};

#endif // VTK_BUILDER_HPP
#include "vtk_builder.hpp"

Vtk_Builder::Vtk_Builder()
{
    renderer = vtkSmartPointer<vtkRenderer>::New();
    renderWindow = vtkSmartPointer<vtkRenderWindow>::New();
    renderWindowInteractor = vtkSmartPointer<vtkRenderWindowInteractor>::New();
    points = vtkSmartPointer<vtkPoints>::New();
    widget = vtkSmartPointer<vtkOrientationMarkerWidget>::New();
    colors = vtkSmartPointer<vtkNamedColors>::New();
    axes = vtkSmartPointer<vtkAxesActor>::New();
    linesBlue = vtkSmartPointer<vtkAppendPolyData>::New();
    linesGreen = vtkSmartPointer<vtkAppendPolyData>::New();
    linesRed = vtkSmartPointer<vtkAppendPolyData>::New();
    cluster1 = vtkSmartPointer<vtkPoints>::New();
    cluster2 = vtkSmartPointer<vtkPoints>::New();
    cluster3 = vtkSmartPointer<vtkPoints>::New();
    cluster4 = vtkSmartPointer<vtkPoints>::New();
    cluster5 = vtkSmartPointer<vtkPoints>::New();
    cluster6 = vtkSmartPointer<vtkPoints>::New();
    cluster7 = vtkSmartPointer<vtkPoints>::New();
    cluster8 = vtkSmartPointer<vtkPoints>::New();
    cluster9 = vtkSmartPointer<vtkPoints>::New();
    cluster10 = vtkSmartPointer<vtkPoints>::New();
    cluster11 = vtkSmartPointer<vtkPoints>::New();
    cluster12 = vtkSmartPointer<vtkPoints>::New();
    cluster13 = vtkSmartPointer<vtkPoints>::New();
    cluster14 = vtkSmartPointer<vtkPoints>::New();
    cluster15 = vtkSmartPointer<vtkPoints>::New();
    cluster16 = vtkSmartPointer<vtkPoints>::New();
    cluster17 = vtkSmartPointer<vtkPoints>::New();
    cluster18 = vtkSmartPointer<vtkPoints>::New();
}

void Vtk_Builder::addClusters(std::vector<std::vector<Vec2D>> clusters)
{
    std::vector<Vec2D> c1 = clusters[0];
    std::vector<Vec2D> c2 = clusters[1];
    std::vector<Vec2D> c3 = clusters[2];
    std::vector<Vec2D> c4 = clusters[3];
    std::vector<Vec2D> c5 = clusters[4];
    std::vector<Vec2D> c6 = clusters[5];
    std::vector<Vec2D> c7 = clusters[6];
    std::vector<Vec2D> c8 = clusters[7];
    std::vector<Vec2D> c9 = clusters[8];
    std::vector<Vec2D> c10 = clusters[9];
    std::vector<Vec2D> c11 = clusters[10];
    std::vector<Vec2D> c12 = clusters[11];
    std::vector<Vec2D> c13 = clusters[12];
    std::vector<Vec2D> c14 = clusters[13];
    std::vector<Vec2D> c15 = clusters[14];
    std::vector<Vec2D> c16 = clusters[15];
    std::vector<Vec2D> c17 = clusters[16];
    std::vector<Vec2D> c18 = clusters[17];
    for (auto &row : c1)
        cluster1->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c2)
        cluster2->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c3)
        cluster3->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c4)
        cluster4->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c5)
        cluster5->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c6)
        cluster6->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c7)
        cluster7->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c8)
        cluster8->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c9)
        cluster9->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c10)
        cluster10->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c11)
        cluster11->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c12)
        cluster12->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c13)
        cluster13->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c14)
        cluster14->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c15)
        cluster15->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c16)
        cluster16->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c17)
        cluster17->InsertNextPoint(row.getX(), row.getY(), 0);
    for (auto &row : c18)
        cluster18->InsertNextPoint(row.getX(), row.getY(), 0);

    vtkNew<vtkPolyData> polyData1;
    polyData1->SetPoints(cluster1);
    vtkNew<vtkVertexGlyphFilter> vertexFilter1;
    vertexFilter1->SetInputData(polyData1);
    vtkNew<vtkPolyDataMapper> mapper1;
    mapper1->SetInputConnection(vertexFilter1->GetOutputPort());
    vtkNew<vtkActor> clusterActor1;
    clusterActor1->SetMapper(mapper1);
    clusterActor1->GetProperty()->SetColor(colors->GetColor3d("Red").GetData());
    clusterActor1->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor1);

    vtkNew<vtkPolyData> polyData2;
    polyData2->SetPoints(cluster2);
    vtkNew<vtkVertexGlyphFilter> vertexFilter2;
    vertexFilter2->SetInputData(polyData2);
    vtkNew<vtkPolyDataMapper> mapper2;
    mapper2->SetInputConnection(vertexFilter2->GetOutputPort());
    vtkNew<vtkActor> clusterActor2;
    clusterActor2->SetMapper(mapper2);
    clusterActor2->GetProperty()->SetColor(colors->GetColor3d("Green").GetData());
    clusterActor2->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor2);

    vtkNew<vtkPolyData> polyData3;
    polyData3->SetPoints(cluster3);
    vtkNew<vtkVertexGlyphFilter> vertexFilter3;
    vertexFilter3->SetInputData(polyData3);
    vtkNew<vtkPolyDataMapper> mapper3;
    mapper3->SetInputConnection(vertexFilter3->GetOutputPort());
    vtkNew<vtkActor> clusterActor3;
    clusterActor3->SetMapper(mapper3);
    clusterActor3->GetProperty()->SetColor(colors->GetColor3d("Blue").GetData());
    clusterActor3->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor3);

    vtkNew<vtkPolyData> polyData4;
    polyData4->SetPoints(cluster4);
    vtkNew<vtkVertexGlyphFilter> vertexFilter4;
    vertexFilter4->SetInputData(polyData4);
    vtkNew<vtkPolyDataMapper> mapper4;
    mapper4->SetInputConnection(vertexFilter4->GetOutputPort());
    vtkNew<vtkActor> clusterActor4;
    clusterActor4->SetMapper(mapper4);
    clusterActor4->GetProperty()->SetColor(colors->GetColor3d("Orange").GetData());
    clusterActor4->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor4);

    vtkNew<vtkPolyData> polyData5;
    polyData5->SetPoints(cluster5);
    vtkNew<vtkVertexGlyphFilter> vertexFilter5;
    vertexFilter5->SetInputData(polyData5);
    vtkNew<vtkPolyDataMapper> mapper5;
    mapper5->SetInputConnection(vertexFilter5->GetOutputPort());
    vtkNew<vtkActor> clusterActor5;
    clusterActor5->SetMapper(mapper5);
    clusterActor5->GetProperty()->SetColor(colors->GetColor3d("Yellow").GetData());
    clusterActor5->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor5);

    vtkNew<vtkPolyData> polyData6;
    polyData6->SetPoints(cluster6);
    vtkNew<vtkVertexGlyphFilter> vertexFilter6;
    vertexFilter6->SetInputData(polyData6);
    vtkNew<vtkPolyDataMapper> mapper6;
    mapper6->SetInputConnection(vertexFilter6->GetOutputPort());
    vtkNew<vtkActor> clusterActor6;
    clusterActor6->SetMapper(mapper6);
    clusterActor6->GetProperty()->SetColor(colors->GetColor3d("Cyan").GetData());
    clusterActor6->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor6);

    vtkNew<vtkPolyData> polyData7;
    polyData7->SetPoints(cluster7);
    vtkNew<vtkVertexGlyphFilter> vertexFilter7;
    vertexFilter7->SetInputData(polyData7);
    vtkNew<vtkPolyDataMapper> mapper7;
    mapper7->SetInputConnection(vertexFilter7->GetOutputPort());
    vtkNew<vtkActor> clusterActor7;
    clusterActor7->SetMapper(mapper7);
    clusterActor7->GetProperty()->SetColor(colors->GetColor3d("Magenta").GetData());
    clusterActor7->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor7);

    vtkNew<vtkPolyData> polyData8;
    polyData8->SetPoints(cluster8);
    vtkNew<vtkVertexGlyphFilter> vertexFilter8;
    vertexFilter8->SetInputData(polyData8);
    vtkNew<vtkPolyDataMapper> mapper8;
    mapper8->SetInputConnection(vertexFilter8->GetOutputPort());
    vtkNew<vtkActor> clusterActor8;
    clusterActor8->SetMapper(mapper8);
    clusterActor8->GetProperty()->SetColor(colors->GetColor3d("Lime").GetData());
    clusterActor8->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor8);

    vtkNew<vtkPolyData> polyData9;
    polyData9->SetPoints(cluster9);
    vtkNew<vtkVertexGlyphFilter> vertexFilter9;
    vertexFilter9->SetInputData(polyData9);
    vtkNew<vtkPolyDataMapper> mapper9;
    mapper9->SetInputConnection(vertexFilter9->GetOutputPort());
    vtkNew<vtkActor> clusterActor9;
    clusterActor9->SetMapper(mapper9);
    clusterActor9->GetProperty()->SetColor(colors->GetColor3d("Pink").GetData());
    clusterActor9->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor9);

    vtkNew<vtkPolyData> polyData10;
    polyData10->SetPoints(cluster10);
    vtkNew<vtkVertexGlyphFilter> vertexFilter10;
    vertexFilter10->SetInputData(polyData10);
    vtkNew<vtkPolyDataMapper> mapper10;
    mapper10->SetInputConnection(vertexFilter10->GetOutputPort());
    vtkNew<vtkActor> clusterActor10;
    clusterActor10->SetMapper(mapper10);
    clusterActor10->GetProperty()->SetColor(colors->GetColor3d("SkyBlue").GetData());
    clusterActor10->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor10);

    vtkNew<vtkPolyData> polyData11;
    polyData11->SetPoints(cluster11);
    vtkNew<vtkVertexGlyphFilter> vertexFilter11;
    vertexFilter11->SetInputData(polyData11);
    vtkNew<vtkPolyDataMapper> mapper11;
    mapper11->SetInputConnection(vertexFilter11->GetOutputPort());
    vtkNew<vtkActor> clusterActor11;
    clusterActor11->SetMapper(mapper11);
    clusterActor11->GetProperty()->SetColor(colors->GetColor3d("SaddleBrown").GetData());
    clusterActor11->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor11);

    vtkNew<vtkPolyData> polyData12;
    polyData12->SetPoints(cluster12);
    vtkNew<vtkVertexGlyphFilter> vertexFilter12;
    vertexFilter12->SetInputData(polyData12);
    vtkNew<vtkPolyDataMapper> mapper12;
    mapper12->SetInputConnection(vertexFilter12->GetOutputPort());
    vtkNew<vtkActor> clusterActor12;
    clusterActor12->SetMapper(mapper12);
    clusterActor12->GetProperty()->SetColor(colors->GetColor3d("Violet").GetData());
    clusterActor12->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor12);

    vtkNew<vtkPolyData> polyData13;
    polyData13->SetPoints(cluster13);
    vtkNew<vtkVertexGlyphFilter> vertexFilter13;
    vertexFilter13->SetInputData(polyData13);
    vtkNew<vtkPolyDataMapper> mapper13;
    mapper13->SetInputConnection(vertexFilter13->GetOutputPort());
    vtkNew<vtkActor> clusterActor13;
    clusterActor13->SetMapper(mapper13);
    clusterActor13->GetProperty()->SetColor(colors->GetColor3d("Aquamarine").GetData());
    clusterActor13->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor13);

    vtkNew<vtkPolyData> polyData14;
    polyData14->SetPoints(cluster14);
    vtkNew<vtkVertexGlyphFilter> vertexFilter14;
    vertexFilter14->SetInputData(polyData14);
    vtkNew<vtkPolyDataMapper> mapper14;
    mapper14->SetInputConnection(vertexFilter14->GetOutputPort());
    vtkNew<vtkActor> clusterActor14;
    clusterActor14->SetMapper(mapper14);
    clusterActor14->GetProperty()->SetColor(colors->GetColor3d("Turquoise").GetData());
    clusterActor14->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor14);

    vtkNew<vtkPolyData> polyData15;
    polyData15->SetPoints(cluster15);
    vtkNew<vtkVertexGlyphFilter> vertexFilter15;
    vertexFilter15->SetInputData(polyData15);
    vtkNew<vtkPolyDataMapper> mapper15;
    mapper15->SetInputConnection(vertexFilter15->GetOutputPort());
    vtkNew<vtkActor> clusterActor15;
    clusterActor15->SetMapper(mapper15);
    clusterActor15->GetProperty()->SetColor(colors->GetColor3d("Tomato").GetData());
    clusterActor15->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor15);

    vtkNew<vtkPolyData> polyData16;
    polyData16->SetPoints(cluster16);
    vtkNew<vtkVertexGlyphFilter> vertexFilter16;
    vertexFilter16->SetInputData(polyData16);
    vtkNew<vtkPolyDataMapper> mapper16;
    mapper16->SetInputConnection(vertexFilter16->GetOutputPort());
    vtkNew<vtkActor> clusterActor16;
    clusterActor16->SetMapper(mapper16);
    clusterActor16->GetProperty()->SetColor(colors->GetColor3d("DeepPink").GetData());
    clusterActor16->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor16);

    vtkNew<vtkPolyData> polyData17;
    polyData17->SetPoints(cluster17);
    vtkNew<vtkVertexGlyphFilter> vertexFilter17;
    vertexFilter17->SetInputData(polyData17);
    vtkNew<vtkPolyDataMapper> mapper17;
    mapper17->SetInputConnection(vertexFilter17->GetOutputPort());
    vtkNew<vtkActor> clusterActor17;
    clusterActor17->SetMapper(mapper17);
    clusterActor17->GetProperty()->SetColor(colors->GetColor3d("Lavender").GetData());
    clusterActor17->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor17);

    vtkNew<vtkPolyData> polyData18;
    polyData18->SetPoints(cluster18);
    vtkNew<vtkVertexGlyphFilter> vertexFilter18;
    vertexFilter18->SetInputData(polyData18);
    vtkNew<vtkPolyDataMapper> mapper18;
    mapper18->SetInputConnection(vertexFilter18->GetOutputPort());
    vtkNew<vtkActor> clusterActor18;
    clusterActor18->SetMapper(mapper18);
    clusterActor18->GetProperty()->SetColor(colors->GetColor3d("SpringGreen").GetData());
    clusterActor18->GetProperty()->SetPointSize(2);
    renderer->AddActor(clusterActor18);
}

void Vtk_Builder::show()
{
    renderWindow->SetWindowName("cLUSTERS");
    renderWindow->AddRenderer(renderer);
    renderWindow->SetSize(renderWindow->GetScreenSize());
    renderWindowInteractor->SetRenderWindow(renderWindow);
    widget->SetOutlineColor(0.9300, 0.5700, 0.1300);
    widget->SetOrientationMarker(axes);
    widget->SetInteractor(renderWindowInteractor);
    widget->SetViewport(0.0, 0.0, 0.2, 0.2);
    widget->SetEnabled(1);
    widget->InteractiveOn();
    renderer->ResetCamera();
    renderWindow->Render();
    renderWindowInteractor->Initialize();
    renderWindowInteractor->Start();
}

void Vtk_Builder::clear()
{
    if (points)
        points->Reset();
    if (linesBlue)
        linesBlue->RemoveAllInputs();
    if (linesGreen)
        linesGreen->RemoveAllInputs();
    if (linesRed)
        linesRed->RemoveAllInputs();
    cluster1->Reset();
    cluster2->Reset();
    cluster3->Reset();
    cluster4->Reset();
    cluster5->Reset();
    cluster6->Reset();
    cluster7->Reset();
    cluster8->Reset();
    cluster9->Reset();
    cluster10->Reset();
    cluster11->Reset();
    cluster12->Reset();
    cluster13->Reset();
    cluster14->Reset();
    cluster15->Reset();
    cluster16->Reset();
    cluster17->Reset();
    cluster18->Reset();
    renderer->RemoveAllViewProps();
}
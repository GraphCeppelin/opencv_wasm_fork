#pragma once

#if !defined YES_I_AGREE_THAT_VIZ_API_IS_NOT_STABLE_NOW_AND_BINARY_COMPARTIBILITY_WONT_BE_SUPPORTED
    //#error "Viz is in beta state now. Please define macro above to use it"
#endif

#include <opencv2/core.hpp>
#include <opencv2/viz/types.hpp>
#include <opencv2/viz/widgets.hpp>

namespace cv
{
    namespace viz
    {
        class CV_EXPORTS Viz3d
        {
        public:
            typedef cv::Ptr<Viz3d> Ptr;
            typedef void (*KeyboardCallback)(const KeyboardEvent&, void*);
            typedef void (*MouseCallback)(const MouseEvent&, void*);

            Viz3d(const String& window_name = String());
            ~Viz3d();

            void setBackgroundColor(const Color& color = Color::black());

            //to refactor
            bool addPolygonMesh(const Mesh3d& mesh, const String& id = "polygon");
            bool updatePolygonMesh(const Mesh3d& mesh, const String& id = "polygon");
            bool addPolylineFromPolygonMesh (const Mesh3d& mesh, const String& id = "polyline");
            bool addPolygon(const Mat& cloud, const Color& color, const String& id = "polygon");


            void showWidget(const String &id, const Widget &widget, const Affine3f &pose = Affine3f::Identity());
            void removeWidget(const String &id);
            Widget getWidget(const String &id) const;

            void setWidgetPose(const String &id, const Affine3f &pose);
            void updateWidgetPose(const String &id, const Affine3f &pose);
            Affine3f getWidgetPose(const String &id) const;
            
            void setCamera(const Camera2 &camera);
            Affine3f getViewerPose();
            void setViewerPose(const Affine3f &pose);

            void spin();
            void spinOnce(int time = 1, bool force_redraw = false);
            bool wasStopped() const;

            void registerKeyboardCallback(KeyboardCallback callback, void* cookie = 0);
            void registerMouseCallback(MouseCallback callback, void* cookie = 0);
        private:
            Viz3d(const Viz3d&);
            Viz3d& operator=(const Viz3d&);

            struct VizImpl;
            VizImpl* impl_;
        };

    } /* namespace viz */
} /* namespace cv */




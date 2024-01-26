#include <sensor_msgs/msg/image.hpp>
#include "rclcpp/rclcpp.hpp"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc/imgproc.hpp"

#include "my_msgss/msg/points.hpp"
#include "my_msgss/msg/point.hpp"
#include "my_msgss/msg/distpoints.hpp"
#include "my_msgss/msg/distpoint.hpp"

#include <bitset>
#include "std_msgs/msg/float32_multi_array.hpp"

using namespace std;
using namespace cv;
using namespace std::chrono_literals;

struct map_point
{
    int id;
    double x;
    double y;
    double z;
};

class MapTest : public rclcpp::Node
{
public:
    MapTest();
    
    void parameter_init();

    void get_map();

    void far_callback(const my_msgss::msg::Distpoints msg);

    void pnp_callback(const std_msgs::msg::Float32MultiArray msg);

    void far_calibration();

    void draw_point_on_map();

    Point2f calculate_pixel_codi(const map_point &point);
private:
    float object_width;
    float object_height;
    float image_width;
    float image_height;


    vector<cv::Point3d> far_objectPoints;
    vector<cv::Point2d> far_imagePoints;
    cv::Mat far_CamMatrix_ =Mat::zeros(3, 3, CV_64FC1);
    cv::Mat far_distCoeffs_ =Mat::zeros(5, 1, CV_64FC1);
    Mat far_Rjacob = Mat::zeros(3, 1, CV_64FC1);
    Mat far_R = Mat::zeros(3, 3, CV_64FC1);
    Mat far_T = Mat::zeros(3, 1, CV_64FC1);
    my_msgss::msg::Points far_points;

    Mat test_map;
    Mat map;

    vector<map_point> map_points;
    
    rclcpp::Publisher<my_msgss::msg::Points>::SharedPtr world_points_pub_;
    rclcpp::Subscription<my_msgss::msg::Distpoints>::SharedPtr far_distpoints_sub_;
    rclcpp::Subscription<std_msgs::msg::Float32MultiArray>::SharedPtr pnp_sub_;
};
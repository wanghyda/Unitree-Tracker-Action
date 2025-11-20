#pragma once

#include <geometry_msgs/msg/detail/transform_stamped__struct.hpp>
#include <vector>

#include "geometry_msgs/msg/pose_stamped.hpp"

class Polygon {
public:
    Polygon(const std::vector<double>& input_coords);
    bool contains(double x, double y) const;
    bool contains(const geometry_msgs::msg::PoseStamped& pose) const;
    bool contains(const geometry_msgs::msg::TransformStamped& pose) const;


private:
    std::vector<std::pair<double, double>> vertices_;
};

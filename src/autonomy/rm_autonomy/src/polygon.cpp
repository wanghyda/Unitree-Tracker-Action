#include "rm_autonomy/polygon.hpp"

Polygon::Polygon(const std::vector<double>& input_coords) {
    for (size_t i = 0; i < input_coords.size(); i += 2) {
        vertices_.emplace_back(input_coords[i], input_coords[i + 1]);
    }
}

// 点是否在多边形内部，示意：
bool Polygon::contains(double x, double y) const {
    // 简单射线法判断点是否在多边形内
    size_t n = vertices_.size();
    bool inside = false;
    for (size_t i = 0, j = n - 1; i < n; j = i++) {
        auto [xi, yi] = vertices_[i];
        auto [xj, yj] = vertices_[j];
        if (((yi > y) != (yj > y)) &&
            (x < (xj - xi) * (y - yi) / (yj - yi + 1e-6) + xi)) {
            inside = !inside;
        }
    }
    return inside;
}

bool Polygon::contains(const geometry_msgs::msg::PoseStamped& pose) const {
    return contains(pose.pose.position.x, pose.pose.position.y);
}

bool Polygon::contains(const geometry_msgs::msg::TransformStamped& pose) const {
    return contains(pose.transform.translation.x, pose.transform.translation.y);
}
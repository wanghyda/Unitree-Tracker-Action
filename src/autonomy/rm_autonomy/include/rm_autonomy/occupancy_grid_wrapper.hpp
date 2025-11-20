#pragma once

#include <nav_msgs/msg/occupancy_grid.hpp>
#include <memory>
#include <vector>
#include <optional>

class OccupancyGridWrapper
{
public:
  using OccupancyGridPtr = std::shared_ptr<nav_msgs::msg::OccupancyGrid>;

  explicit OccupancyGridWrapper(OccupancyGridPtr grid);

  int getWidth() const;
  int getHeight() const;
  float getResolution() const;

  float getOriginX() const;
  float getOriginY() const;

  // 获取 cost 值（若坐标非法，返回 std::nullopt）
  std::optional<int8_t> getCost(int mx, int my) const;

  // 世界坐标系 → 栅格坐标系
  bool worldToMap(float wx, float wy, int &mx, int &my) const;

  // 栅格坐标系 → 世界坐标系
  void mapToWorld(int mx, int my, float &wx, float &wy) const;

  // 获取整个代价矩阵（二维）
  const std::vector<std::vector<int8_t>>& getCostmap2D() const;

private:
  int width_;
  int height_;
  float resolution_;
  float origin_x_;
  float origin_y_;
  std::vector<std::vector<int8_t>> costmap_2d_;
};

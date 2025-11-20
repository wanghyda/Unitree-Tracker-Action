#include "rm_autonomy/occupancy_grid_wrapper.hpp"

OccupancyGridWrapper::OccupancyGridWrapper(OccupancyGridPtr grid)
{
  width_ = grid->info.width;
  height_ = grid->info.height;
  resolution_ = grid->info.resolution;
  origin_x_ = grid->info.origin.position.x;
  origin_y_ = grid->info.origin.position.y;

  const auto &data = grid->data;
  costmap_2d_.resize(height_, std::vector<int8_t>(width_, -1));

  for (int y = 0; y < height_; ++y)
  {
    for (int x = 0; x < width_; ++x)
    {
      int idx = y * width_ + x;
      if (idx < static_cast<int>(data.size()))
      {
        costmap_2d_[y][x] = data[idx];
      }
    }
  }
}

int OccupancyGridWrapper::getWidth() const { return width_; }
int OccupancyGridWrapper::getHeight() const { return height_; }
float OccupancyGridWrapper::getResolution() const { return resolution_; }
float OccupancyGridWrapper::getOriginX() const { return origin_x_; }
float OccupancyGridWrapper::getOriginY() const { return origin_y_; }

std::optional<int8_t> OccupancyGridWrapper::getCost(int mx, int my) const
{
  if (mx < 0 || my < 0 || mx >= width_ || my >= height_)
    return std::nullopt;

  return costmap_2d_[my][mx];  // 注意 y 是行
}

bool OccupancyGridWrapper::worldToMap(float wx, float wy, int &mx, int &my) const
{
  if (wx < origin_x_ || wy < origin_y_)
    return false;

  mx = static_cast<int>((wx - origin_x_) / resolution_);
  my = static_cast<int>((wy - origin_y_) / resolution_);

  return mx >= 0 && my >= 0 && mx < width_ && my < height_;
}

void OccupancyGridWrapper::mapToWorld(int mx, int my, float &wx, float &wy) const
{
  wx = origin_x_ + (mx + 0.5f) * resolution_;
  wy = origin_y_ + (my + 0.5f) * resolution_;
}

const std::vector<std::vector<int8_t>> &OccupancyGridWrapper::getCostmap2D() const
{
  return costmap_2d_;
}

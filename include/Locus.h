#pragma once

#include <QGLShaderProgram>
#include <QVector3D>
#include <QVector>

namespace Locus {

class Locus final {
public:
    Locus(QVector<QVector3D> &&points_, QVector<QVector3D> &&colors_);
    Locus() = default;
    ~Locus() = default;

    const QVector3D *pointsData() const;
    const QVector3D *colorsData() const;

    size_t size() const;

private:
    QVector<QVector3D> points;
    QVector<QVector3D> colors;

    QVector3D getInterpolatedPoint(float offset, size_t startIndex);

    void interpolate();
};

class LocusController final {
public:
    LocusController()  = default;
    ~LocusController() = default;

    LocusController(const LocusController &)            = delete;
    LocusController(LocusController &&)                 = delete;
    LocusController &operator=(const LocusController &) = delete;
    LocusController &operator=(LocusController &&)      = delete;

    size_t size() const;

    void addLocus(Locus &&locus);
    void removeLocus(size_t index);

    void clear();

    void draw(QGLShaderProgram &shaderProgram, size_t amount) const;
private:
    QVector<Locus> data;
};

} //namespace Locus

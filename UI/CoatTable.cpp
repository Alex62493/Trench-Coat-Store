//
// Created by Alex on 03.06.2021.
//

#include "CoatTable.h"

#include <utility>

void split(const std::string &str, const std::string &delim, std::vector<std::string> &parts) {
    size_t start, end = 0;
    while (end < str.size()) {
        start = end;
        while (start < str.size() && (delim.find(str[start]) != std::string::npos)) {
            start++;
        }
        end = start;
        while (end < str.size() && (delim.find(str[end]) == std::string::npos)) {
            end++;
        }
        if (end-start != 0) {
            parts.push_back(std::string(str, start, end-start));
        }
    }
}

CoatModel::CoatModel(QObject *parent) : QAbstractTableModel(parent) {
}

int CoatModel::rowCount(const QModelIndex &) const {
    return this->trenchCoats.size();
}

int CoatModel::columnCount(const QModelIndex &) const {
    return 6;
}

QVariant CoatModel::data(const QModelIndex &index, int role) const {
    if (role != Qt::DisplayRole && role != Qt::EditRole) return {};
    const auto & coat = m_data[index.row()];
    return QString::fromStdString(coat[index.column()]);
}

QVariant CoatModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation != Qt::Horizontal || role != Qt::DisplayRole) return {};
    switch (section) {
        case 0: return "ID";
        case 1: return "Size";
        case 2: return "Colour";
        case 3: return "Price";
        case 4: return "Quantity";
        case 5: return "Photograph";
        default: return {};
    }
}

void CoatModel::updateVector(std::vector<std::string> newCoats) {
    this->m_data.clear();
    this->trenchCoats = std::move(newCoats);
    for (auto & trenchCoat : this->trenchCoats) {
        std::vector<std::string> coat;
        split(trenchCoat, "-", coat);
        beginInsertRows({}, m_data.count(), m_data.count());
        m_data.append(coat);
        endInsertRows();
    }
}
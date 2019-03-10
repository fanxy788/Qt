#include "tablemodel.h"
#include <QColor>

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{

}

TableModel::~TableModel()
{

}

// 更新表格数据
void TableModel::updateData(QList<FileRecord> recordList)
{
    m_recordList = recordList;
    beginResetModel();
    endResetModel();
}

// 行数
int TableModel::rowCount(const QModelIndex &parent) const
{
    return m_recordList.count();
}

// 列数
int TableModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

// 设置表格项数据
bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid())
        return false;
    int nColumn = index.column();
    FileRecord record = m_recordList.at(index.row());
    switch (role)
    {
    case Qt::DisplayRole:
    {
        if (nColumn == File_PATH_COLUMN)
        {
            record.strFilePath = value.toString();
            m_recordList.replace(index.row(), record);
            emit dataChanged(index, index);
            return true;
        }
    }
    case Qt::CheckStateRole:
    {
        if (nColumn == CHECK_BOX_COLUMN)
        {
            record.bChecked = (value.toInt() == Qt::Checked);
            m_recordList.replace(index.row(), record);
            emit dataChanged(index, index);
            return true;
        }
    }
    default:
        return false;
    }
    return false;
}

// 表格项数据
QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    int nRow = index.row();
    int nColumn = index.column();
    FileRecord record = m_recordList.at(nRow);
    switch (role)
    {
    case Qt::TextColorRole:
        return QColor(Qt::white);
    case Qt::TextAlignmentRole:
        return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
    case Qt::DisplayRole:
    {
        if (nColumn == File_PATH_COLUMN)
            return record.strFilePath;
        return "";
    }
    case Qt::CheckStateRole:
    {
        if (nColumn == CHECK_BOX_COLUMN)
            return record.bChecked ? Qt::Checked : Qt::Unchecked;
    }
    default:
        return QVariant();
    }
    return QVariant();
}

// 表头数据
QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    switch (role)
    {
    case Qt::TextAlignmentRole:
        return QVariant(Qt::AlignLeft | Qt::AlignVCenter);
    case Qt::DisplayRole:
    {
        if (orientation == Qt::Horizontal)
        {
            if (section == CHECK_BOX_COLUMN)
                return QStringLiteral("状态");
            if (section == File_PATH_COLUMN)
                return QStringLiteral("文件路径");
        }
    }
    default:
        return QVariant();
    }
    return QVariant();
}

// 表格可选中、可复选
Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return QAbstractItemModel::flags(index);
    Qt::ItemFlags flags = Qt::ItemIsEnabled | Qt::ItemIsSelectable;
    if (index.column() == CHECK_BOX_COLUMN)
        flags |= Qt::ItemIsUserCheckable;
    return flags;
}


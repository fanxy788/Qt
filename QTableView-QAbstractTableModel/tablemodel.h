#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>


#define CHECK_BOX_COLUMN 0
#define File_PATH_COLUMN 1

typedef struct FileRecord
{
    bool bChecked; //是否选中
    QString strFilePath; //文件路径
}fileRecord;

class TableModel : public QAbstractTableModel
{
public:
    TableModel(QObject *parent = 0);
    ~TableModel();

    void updateData(QList<FileRecord> recordList);
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;

private:
    QList<FileRecord> m_recordList;
};

#endif // TABLEMODEL_H

#include "utils.h"

#include <KF5/KScreen/kscreen/output.h>
#include <KF5/KScreen/kscreen/edid.h>

//#include <KLocalizedString>

QString Utils::outputName(const KScreen::OutputPtr& output)
{
    //qDebug()<<"显示器名称-------->"<<outputName(output.data());
    return outputName(output.data());
}

QString Utils::outputName(const KScreen::Output *output)
{
//    if (output->type() == KScreen::Output::Panel) {
//        return i18n("Laptop Screen");
//    }

    if (output->edid()) {
        // The name will be "VendorName ModelName (ConnectorName)",
        // but some components may be empty.
        QString name;
        if (!(output->edid()->vendor().isEmpty())) {
            name = output->edid()->vendor() + QLatin1Char(' ');
        }
        if (!output->edid()->name().isEmpty()) {
            name += output->edid()->name() + QLatin1Char(' ');
        }
        if (!name.trimmed().isEmpty()) {
            return name + QLatin1Char('(') + output->name() + QLatin1Char(')');
        }
    }
    //qDebug()<<"显示器名称-------->"<<output->name();
    return output->name();
}

QString Utils::sizeToString(const QSize &size)
{
    return QStringLiteral("%1x%2").arg(size.width()).arg(size.height());
}


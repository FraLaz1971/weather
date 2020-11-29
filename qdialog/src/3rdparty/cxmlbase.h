#ifndef __QXMLBASE_H__
#define __QXMLBASE_H__

#define __S2U(string) QString(string)
#define __U2S(string) QString(string)

bool nodeToVariant(const QDomNode &aNode, QVariant &aValue);
bool variantToNode(const QVariant &aValue, QDomElement &aElement);

#endif // __QXMLBASE_H__

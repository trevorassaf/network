#include "address_family_translator.h"

#include <sys/types.h>
#include <sys/socket.h>

const Network::Linux::AddressFamilyTranslator::AddressFamilyToOsCodeMap
Network::Linux::AddressFamilyTranslator::ADDRESS_FAMILY_TO_OS_CODE_MAP = {
  {Network::Ip::AddressFamily::V4, AF_INET},
  {Network::Ip::AddressFamily::V6, AF_INET6},
  {Network::Ip::AddressFamily::UNSPECIFIED, AF_UNSPEC}
};

const Network::Linux::AddressFamilyTranslator::OsCodeToAddressFamilyMap
Network::Linux::AddressFamilyTranslator::OS_CODE_TO_ADDRESS_FAMILY_MAP = {
  {AF_INET, Network::Ip::AddressFamily::V4},
  {AF_INET6, Network::Ip::AddressFamily::V6},
  {AF_UNSPEC, Network::Ip::AddressFamily::UNSPECIFIED}
};

int Network::Linux::AddressFamilyTranslator::translateToOsCode(
    Network::Ip::AddressFamily address_family
) const {
  return ADDRESS_FAMILY_TO_OS_CODE_MAP.at(address_family);
}

Network::Ip::AddressFamily Network::Linux::AddressFamilyTranslator::translateFromOsCode(int os_code) const {
  return OS_CODE_TO_ADDRESS_FAMILY_MAP.at(os_code);
}

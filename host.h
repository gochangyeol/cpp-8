#ifndef HOST_H
#define HOST_H

#include "address.h"
#include "packet.h"
#include "service.h"
#include <vector>

class Host : public Node {
  friend class ServiceInstaller;

private:
  // 호스트의 주소
  Address address_;

  // 설치된 서비스 목록
  std::vector<Service *> services_;

public:
  Address address() { return address_; }
  Host(Address address) : address_(address) {}

  void addService(Service *service) {
        services_.push_back(service);
    }

  // 호스트와 설치된 서비스를 전부 초기화한다.
  void initialize(){
    services_.clear();
    std::vector<Service*>().swap(services_);
  }

  // 링크를 랜덤으로 하나 선택하여 패킷을 전송한다.
  void send(Packet *packet){
     std::string Add=packet->srcAddress().toString();
     std::string desAdd=packet->destAddress().toString();

     std::cout<<"Host #"<<Add<<": sending packet "<<"(from: "<<desAdd<<", to: "<<Add<<", "<<sizeof(packet->data())<<" bytes)"<<std::endl;
  }
  void received(Packet *packet){
    std::cout<<"Host #"<<packet->destAddress().toString()<<": received packet, destination port: "<<packet->destPort()<<std::endl;
  }
};

#endif
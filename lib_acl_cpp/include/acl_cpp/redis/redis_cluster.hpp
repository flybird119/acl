#pragma once
#include "acl_cpp/acl_cpp_define.hpp"
#include "acl_cpp/connpool/connect_manager.hpp"

namespace acl
{

class ACL_CPP_API redis_cluster : public connect_manager
{
public:
	/**
	 * ���캯��
	 * @param conn_timeout {int} ���������ӳ�ʱʱ��(��)
	 * @param rw_timeout {int}������ IO ��д��ʱʱ��(��)
	 */
	redis_cluster(int conn_timeout, int rw_timeout);
	virtual ~redis_cluster();

protected:
	/**
	 * ���ി�麯���������������ӳض���
	 * @param addr {const char*} ������������ַ����ʽ��ip:port
	 * @param count {int} ���ӳصĴ�С����
	 * @param idx {size_t} �����ӳض����ڼ����е��±�λ��(�� 0 ��ʼ)
	 */
	virtual acl::connect_pool* create_pool(const char* addr,
		int count, size_t idx);
private:
	int   conn_timeout_;
	int   rw_timeout_;
};

} // namespace acl
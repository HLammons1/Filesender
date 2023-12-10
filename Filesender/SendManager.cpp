#include "SendManager.h"

bool SendManager::ManageSend(std::string filePath)
{
	std::unique_ptr<std::string> pFileText = std::make_unique<std::string>(fileReader->ReturnFileString(filePath));
	pFileText = converter->TextToMultipleOf16(std::move(pFileText));

	std::vector<unsigned char> key(32, 0x00);
	std::vector<unsigned char> iv(16, 0x00);

	AES aes(AESKeyLength::AES_256);

	std::vector<unsigned char> encryptedData = aes.EncryptCBC(
		std::vector<unsigned char>(pFileText->begin(), pFileText->end()),
		key, iv
	);

	std::vector<std::vector<unsigned char>> dataToSend = { encryptedData, key, iv };
	sendFile->Send(dataToSend);
	return false;
}
